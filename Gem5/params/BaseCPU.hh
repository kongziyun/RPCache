#ifndef __PARAMS__BaseCPU__
#define __PARAMS__BaseCPU__

class BaseCPU;

#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/X86TLB.hh"
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/BaseCPU.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/X86LocalApic.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <vector>
#include "params/Process.hh"
#include <cstddef>
#include "params/X86TLB.hh"
#include <vector>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/BranchPredictor.hh"
#include <vector>
#include "params/X86ISA.hh"
#include <cstddef>
#include "params/InstTracer.hh"

#include "params/MemObject.hh"

struct BaseCPUParams
    : public MemObjectParams
{
    bool do_statistics_insts;
    unsigned numThreads;
    X86ISA::TLB * itb;
    bool function_trace;
    bool do_checkpoint_insts;
    Counter max_loads_all_threads;
    System * system;
    Tick function_trace_start;
    int cpu_id;
    BaseCPU * checker;
    bool do_quiesce;
    Tick profile;
    X86ISA::Interrupts * interrupts;
    Counter max_insts_all_threads;
    Counter max_loads_any_thread;
    bool switched_out;
    std::vector< Process * > workload;
    X86ISA::TLB * dtb;
    std::vector< Counter > simpoint_start_insts;
    Counter max_insts_any_thread;
    Tick progress_interval;
    BPredUnit * branchPred;
    std::vector< X86ISA::ISA * > isa;
    Trace::InstTracer * tracer;
    unsigned int port_icache_port_connection_count;
    unsigned int port_dcache_port_connection_count;
};

#endif // __PARAMS__BaseCPU__
