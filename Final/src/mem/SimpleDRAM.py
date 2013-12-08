# Copyright (c) 2012-2013 ARM Limited
# All rights reserved.
#
# The license below extends only to copyright in the software and shall
# not be construed as granting a license to any other intellectual
# property including but not limited to intellectual property relating
# to a hardware implementation of the functionality of the software
# licensed hereunder.  You may use the software subject to the license
# terms below provided that you ensure that this notice is replicated
# unmodified and in its entirety in all distributions of the software,
# modified or unmodified, in source code or in binary form.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met: redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer;
# redistributions in binary form must reproduce the above copyright
# notice, this list of conditions and the following disclaimer in the
# documentation and/or other materials provided with the distribution;
# neither the name of the copyright holders nor the names of its
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# Authors: Andreas Hansson
#          Ani Udipi

from m5.params import *
from AbstractMemory import *

# Enum for memory scheduling algorithms, currently First-Come
# First-Served and a First-Row Hit then First-Come First-Served
class MemSched(Enum): vals = ['fcfs', 'frfcfs']

# Enum for the address mapping. With Ra, Co, Ba and Ch denoting rank,
# column, bank and channel, respectively, and going from MSB to LSB.
# Available are RaBaChCo and RaBaCoCh, that are suitable for an
# open-page policy, optimising for sequential accesses hitting in the
# open row. For a closed-page policy, CoRaBaCh maximises parallelism.
class AddrMap(Enum): vals = ['RaBaChCo', 'RaBaCoCh', 'CoRaBaCh']

# Enum for the page policy, either open or close.
class PageManage(Enum): vals = ['open', 'close']

# SimpleDRAM is a single-channel single-ported DRAM controller model
# that aims to model the most important system-level performance
# effects of a DRAM without getting into too much detail of the DRAM
# itself.
class SimpleDRAM(AbstractMemory):
    type = 'SimpleDRAM'
    cxx_header = "mem/simple_dram.hh"

    @classmethod
    def makeMultiChannel(cls, nbr_mem_ctrls, mem_start_addr, mem_size,
                         intlv_high_bit = 11):
        """
        Make a multi-channel configuration of this class.

        Create multiple instances of the specific class and set their
        parameters such that the address range is interleaved between
        them.

        Returns a list of controllers.
        """
        import math
        from m5.util import fatal
        intlv_bits = int(math.log(nbr_mem_ctrls, 2))
        if 2 ** intlv_bits != nbr_mem_ctrls:
            fatal("Number of memory channels must be a power of 2")
        mem_ctrls = []
        for i in xrange(nbr_mem_ctrls):
            # The default interleaving granularity is tuned to match a
            # row buffer size of 32 cache lines of 64 bytes (starting
            # at bit 11 for 2048 bytes). There is unfortunately no
            # good way of checking this at instantiation time.
            mem_ctrls.append(cls(range = AddrRange(mem_start_addr,
                                                   size = mem_size,
                                                   intlvHighBit = \
                                                       intlv_high_bit,
                                                   intlvBits = intlv_bits,
                                                   intlvMatch = i),
                                 channels = nbr_mem_ctrls))
        return mem_ctrls

    # single-ported on the system interface side, instantiate with a
    # bus in front of the controller for multiple ports
    port = SlavePort("Slave port")

    # the basic configuration of the controller architecture
    write_buffer_size = Param.Unsigned(32, "Number of read queue entries")
    read_buffer_size = Param.Unsigned(32, "Number of write queue entries")

    # threshold in percent for when to trigger writes and start
    # emptying the write buffer as it starts to get full
    write_thresh_perc = Param.Percent(70, "Threshold to trigger writes")

    # scheduler, address map and page policy
    mem_sched_policy = Param.MemSched('frfcfs', "Memory scheduling policy")
    addr_mapping = Param.AddrMap('RaBaChCo', "Address mapping policy")
    page_policy = Param.PageManage('open', "Page closure management policy")

    # pipeline latency of the controller and PHY, split into a
    # frontend part and a backend part, with reads and writes serviced
    # by the queues only seeing the frontend contribution, and reads
    # serviced by the memory seeing the sum of the two
    static_frontend_latency = Param.Latency("10ns", "Static frontend latency")
    static_backend_latency = Param.Latency("10ns", "Static backend latency")

    # the physical organisation of the DRAM
    lines_per_rowbuffer = Param.Unsigned("Row buffer size in cache lines")
    ranks_per_channel = Param.Unsigned("Number of ranks per channel")
    banks_per_rank = Param.Unsigned("Number of banks per rank")
    # only used for the address mapping as the controller by
    # construction is a single channel and multiple controllers have
    # to be instantiated for a multi-channel configuration
    channels = Param.Unsigned(1, "Number of channels")

    # timing behaviour and constraints - all in nanoseconds

    # the amount of time in nanoseconds from issuing an activate command
    # to the data being available in the row buffer for a read/write
    tRCD = Param.Latency("RAS to CAS delay")

    # the time from issuing a read/write command to seeing the actual data
    tCL = Param.Latency("CAS latency")

    # minimum time between a precharge and subsequent activate
    tRP = Param.Latency("Row precharge time")

    # time to complete a burst transfer, typically the burst length
    # divided by two due to the DDR bus, but by making it a parameter
    # it is easier to also evaluate SDR memories like WideIO.
    # This parameter has to account for bus width and burst length.
    # Adjustment also necessary if cache line size is greater than
    # data size read/written by one full burst.
    tBURST = Param.Latency("Burst duration (for DDR burst length / 2 cycles)")

    # time taken to complete one refresh cycle (N rows in all banks)
    tRFC = Param.Latency("Refresh cycle time")

    # refresh command interval, how often a "ref" command needs
    # to be sent. It is 7.8 us for a 64ms refresh requirement
    tREFI = Param.Latency("Refresh command interval")

    # write-to-read turn around penalty, assumed same as read-to-write
    tWTR = Param.Latency("Write to read switching time")

    # time window in which a maximum number of activates are allowed
    # to take place, set to 0 to disable
    tXAW = Param.Latency("X activation window")
    activation_limit = Param.Unsigned("Max number of activates in window")

    # Currently rolled into other params
    ######################################################################

    # the minimum amount of time between a row being activated, and
    # precharged (de-activated)
    # tRAS - assumed to be 3 * tRP

    # tRC  - assumed to be 4 * tRP

    # burst length for an access derived from peerBlockSize

# A single DDR3 x64 interface (one command and address bus), with
# default timings based on DDR3-1600 4 Gbit parts in an 8x8
# configuration, which would amount to 4 Gbyte of memory.
class DDR3_1600_x64(SimpleDRAM):
    # Assuming 64 byte cache lines, and a 1kbyte page size per module
    # (this depends on the memory density)
    lines_per_rowbuffer = 128

    # Use two ranks
    ranks_per_channel = 2

    # DDR3 has 8 banks in all configurations
    banks_per_rank = 8

    # DDR3-1600 11-11-11
    tRCD = '13.75ns'
    tCL = '13.75ns'
    tRP = '13.75ns'

    # Assuming 64 byte cache lines, across an x64
    # interface, translates to BL8, 4 clocks @ 800 MHz
    tBURST = '5ns'

    # DDR3, 4 Gbit has a tRFC of 240 CK and tCK = 1.25 ns
    tRFC = '300ns'

    # DDR3, <=85C, half for >85C
    tREFI = '7.8us'

    # Greater of 4 CK or 7.5 ns, 4 CK @ 800 MHz = 5 ns
    tWTR = '7.5ns'

    # With a 2kbyte page size, DDR3-1600 lands around 40 ns
    tXAW = '40ns'
    activation_limit = 4


# A single LPDDR2-S4 x32 interface (one command/address bus), with
# default timings based on a LPDDR2-1066 4 Gbit part in a 1x32
# configuration.
class LPDDR2_S4_1066_x32(SimpleDRAM):
    # Assuming 64 byte cache lines, use a 1kbyte page size, this
    # depends on the memory density
    lines_per_rowbuffer = 16

    # Use a single rank
    ranks_per_channel = 1

    # LPDDR2-S4 has 8 banks in all configurations
    banks_per_rank = 8

    # Fixed at 15 ns
    tRCD = '15ns'

    # 8 CK read latency, 4 CK write latency @ 533 MHz, 1.876 ns cycle time
    tCL = '15ns'

    # Pre-charge one bank 15 ns (all banks 18 ns)
    tRP = '15ns'

    # Assuming 64 byte cache lines, across a x32 DDR interface
    # translates to two BL8, 8 clocks @ 533 MHz. Note that this is a
    # simplification
    tBURST = '15ns'

    # LPDDR2-S4, 4 Gbit
    tRFC = '130ns'
    tREFI = '3.9us'

    # Irrespective of speed grade, tWTR is 7.5 ns
    tWTR = '7.5ns'

    # Irrespective of density, tFAW is 50 ns
    tXAW = '50ns'
    activation_limit = 4

# A single WideIO x128 interface (one command and address bus), with
# default timings based on an estimated WIO-200 8 Gbit part.
class WideIO_200_x128(SimpleDRAM):
    # Assuming 64 byte cache lines, use a 4kbyte page size, this
    # depends on the memory density
    lines_per_rowbuffer = 64

    # Use one rank for a one-high die stack
    ranks_per_channel = 1

    # WideIO has 4 banks in all configurations
    banks_per_rank = 4

    # WIO-200
    tRCD = '18ns'
    tCL = '18ns'
    tRP = '18ns'

    # Assuming 64 byte cache lines, across an x128 SDR interface,
    # translates to BL4, 4 clocks @ 200 MHz
    tBURST = '20ns'

    # WIO 8 Gb
    tRFC = '210ns'

    # WIO 8 Gb, <=85C, half for >85C
    tREFI = '3.9us'

    # Greater of 2 CK or 15 ns, 2 CK @ 200 MHz = 10 ns
    tWTR = '15ns'

    # Two instead of four activation window
    tXAW = '50ns'
    activation_limit = 2

# A single LPDDR3 x32 interface (one command/address bus), with
# default timings based on a LPDDR3-1600 4 Gbit part in a 1x32
# configuration
class LPDDR3_1600_x32(SimpleDRAM):
    # 4 Gbit and 8 Gbit devices use a 1 kByte page size, so ssuming 64
    # byte cache lines, that is 16 lines
    lines_per_rowbuffer = 16

    # Use a single rank
    ranks_per_channel = 1

    # LPDDR3 has 8 banks in all configurations
    banks_per_rank = 8

    # Fixed at 15 ns
    tRCD = '15ns'

    # 12 CK read latency, 6 CK write latency @ 800 MHz, 1.25 ns cycle time
    tCL = '15ns'

    # Pre-charge one bank 15 ns (all banks 18 ns)
    tRP = '15ns'

    # Assuming 64 byte cache lines, across a x32 DDR interface
    # translates to two bursts of BL8, 8 clocks @ 800 MHz
    tBURST = '10ns'

    # LPDDR3, 4 Gb
    tRFC = '130ns'
    tREFI = '3.9us'

    # Irrespective of speed grade, tWTR is 7.5 ns
    tWTR = '7.5ns'

    # Irrespective of size, tFAW is 50 ns
    tXAW = '50ns'
    activation_limit = 4
