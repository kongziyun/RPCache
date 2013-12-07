#ifndef __PARAMS__BaseTags__
#define __PARAMS__BaseTags__

class BaseTags;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/ClockedObject.hh"

struct BaseTagsParams
    : public ClockedObjectParams
{
    uint64_t size;
    int block_size;
    Cycles hit_latency;
};

#endif // __PARAMS__BaseTags__
