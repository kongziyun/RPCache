#ifndef __PARAMS__RubySystem__
#define __PARAMS__RubySystem__

class RubySystem;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include <cstddef>

#include "params/ClockedObject.hh"

struct RubySystemParams
    : public ClockedObjectParams
{
    RubySystem * create();
    int random_seed;
    uint64_t mem_size;
    uint32_t block_size_bytes;
    std::string stats_filename;
    bool randomization;
    bool no_mem_vec;
};

#endif // __PARAMS__RubySystem__
