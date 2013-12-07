#ifndef __PARAMS__AbstractMemory__
#define __PARAMS__AbstractMemory__

class AbstractMemory;

#include <cstddef>
#include "base/types.hh"
#include "base/addr_range.hh"
#include <cstddef>
#include <cstddef>
#include <cstddef>

#include "params/MemObject.hh"

struct AbstractMemoryParams
    : public MemObjectParams
{
    AddrRange range;
    bool null;
    bool conf_table_reported;
    bool in_addr_map;
};

#endif // __PARAMS__AbstractMemory__
