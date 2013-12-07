#ifndef __PARAMS__BasePrefetcher__
#define __PARAMS__BasePrefetcher__

class BasePrefetcher;

#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"

#include "params/ClockedObject.hh"

struct BasePrefetcherParams
    : public ClockedObjectParams
{
    bool data_accesses_only;
    Cycles latency;
    bool use_master_id;
    int degree;
    System * sys;
    bool serial_squash;
    bool cross_pages;
    int size;
};

#endif // __PARAMS__BasePrefetcher__
