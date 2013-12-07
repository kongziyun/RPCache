#ifndef __PARAMS__CoherentBus__
#define __PARAMS__CoherentBus__

class CoherentBus;

#include <cstddef>
#include "params/System.hh"

#include "params/BaseBus.hh"

struct CoherentBusParams
    : public BaseBusParams
{
    CoherentBus * create();
    System * system;
};

#endif // __PARAMS__CoherentBus__
