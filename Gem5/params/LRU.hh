#ifndef __PARAMS__LRU__
#define __PARAMS__LRU__

class LRU;

#include <cstddef>
#include "base/types.hh"

#include "params/BaseTags.hh"

struct LRUParams
    : public BaseTagsParams
{
    LRU * create();
    int assoc;
};

#endif // __PARAMS__LRU__
