#ifndef __PARAMS__AtomicSimpleCPU__
#define __PARAMS__AtomicSimpleCPU__

class AtomicSimpleCPU;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>

#include "params/BaseSimpleCPU.hh"

struct AtomicSimpleCPUParams
    : public BaseSimpleCPUParams
{
    AtomicSimpleCPU * create();
    uint64_t simpoint_interval;
    bool simulate_inst_stalls;
    bool simpoint_profile;
    bool simulate_data_stalls;
    std::string simpoint_profile_file;
    int width;
    bool fastmem;
};

#endif // __PARAMS__AtomicSimpleCPU__
