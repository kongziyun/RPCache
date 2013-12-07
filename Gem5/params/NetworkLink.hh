#ifndef __PARAMS__NetworkLink__
#define __PARAMS__NetworkLink__

class NetworkLink;

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

struct NetworkLinkParams
    : public ClockedObjectParams
{
    NetworkLink * create();
    int virt_nets;
    int link_id;
    int vcs_per_vnet;
    int channel_width;
    Cycles link_latency;
};

#endif // __PARAMS__NetworkLink__
