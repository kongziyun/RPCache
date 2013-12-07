#ifndef __PARAMS__BaseCache__
#define __PARAMS__BaseCache__

class BaseCache;

#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "params/BaseTags.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include "params/BasePrefetcher.hh"
#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"

#include "params/MemObject.hh"

struct BaseCacheParams
    : public MemObjectParams
{
    BaseCache * create();
    bool two_queue;
    bool prefetch_on_access;
    Cycles hit_latency;
    bool isIcache;
    BaseTags * tags;
    int tgts_per_mshr;
    System * system;
    BasePrefetcher * prefetcher;
    std::vector< AddrRange > addr_ranges;
    Counter max_miss_count;
    int write_buffers;
    Cycles response_latency;
    bool is_top_level;
    int assoc;
    int block_size;
    int mshrs;
    bool forward_snoops;
    uint64_t size;
    unsigned int port_mem_side_connection_count;
    unsigned int port_cpu_side_connection_count;
};

#endif // __PARAMS__BaseCache__
