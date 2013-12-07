#ifndef __PARAMS__SimpleDRAM__
#define __PARAMS__SimpleDRAM__

class SimpleDRAM;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "enums/PageManage.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "enums/MemSched.hh"
#include <cstddef>
#include "enums/AddrMap.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/AbstractMemory.hh"

#include "enums/PageManage.hh"

#include "enums/MemSched.hh"

#include "enums/AddrMap.hh"

struct SimpleDRAMParams
    : public AbstractMemoryParams
{
    SimpleDRAM * create();
    Tick tRFC;
    unsigned activation_limit;
    int write_thresh_perc;
    Tick tWTR;
    Tick static_frontend_latency;
    Tick tXAW;
    Tick tREFI;
    unsigned channels;
    unsigned ranks_per_channel;
    Tick tCL;
    unsigned write_buffer_size;
    unsigned banks_per_rank;
    Tick tRP;
    Tick static_backend_latency;
    Enums::PageManage page_policy;
    Tick tBURST;
    Enums::MemSched mem_sched_policy;
    Enums::AddrMap addr_mapping;
    Tick tRCD;
    unsigned lines_per_rowbuffer;
    unsigned read_buffer_size;
    unsigned int port_port_connection_count;
};

#endif // __PARAMS__SimpleDRAM__
