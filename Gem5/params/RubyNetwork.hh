#ifndef __PARAMS__RubyNetwork__
#define __PARAMS__RubyNetwork__

class Network;

#include <vector>
#include "params/BasicIntLink.hh"
#include <vector>
#include "params/BasicRouter.hh"
#include <vector>
#include "params/BasicExtLink.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/RubySystem.hh"
#include <cstddef>
#include <string>

#include "params/ClockedObject.hh"

struct RubyNetworkParams
    : public ClockedObjectParams
{
    std::vector< BasicIntLink * > int_links;
    std::vector< BasicRouter * > routers;
    std::vector< BasicExtLink * > ext_links;
    int number_of_virtual_networks;
    int control_msg_size;
    RubySystem * ruby_system;
    std::string topology;
};

#endif // __PARAMS__RubyNetwork__
