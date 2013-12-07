#ifndef __PARAMS__SrcClockDomain__
#define __PARAMS__SrcClockDomain__

class SrcClockDomain;

#include <cstddef>
#include "base/types.hh"

#include "params/ClockDomain.hh"

struct SrcClockDomainParams
    : public ClockDomainParams
{
    SrcClockDomain * create();
    Tick clock;
};

#endif // __PARAMS__SrcClockDomain__
