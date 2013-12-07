#ifndef __PARAMS__NetworkLink_d__
#define __PARAMS__NetworkLink_d__

class NetworkLink_d;

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

#include "params/ClockedObject.hh"

struct NetworkLink_dParams
    : public ClockedObjectParams
{
    NetworkLink_d * create();
    int virt_nets;
    int link_id;
    int vcs_per_vnet;
    int channel_width;
    Cycles link_latency;
};

#endif // __PARAMS__NetworkLink_d__
