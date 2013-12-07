#ifndef __PARAMS__DerivedClockDomain__
#define __PARAMS__DerivedClockDomain__

class DerivedClockDomain;

#include <cstddef>
#include "params/ClockDomain.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/ClockDomain.hh"

struct DerivedClockDomainParams
    : public ClockDomainParams
{
    DerivedClockDomain * create();
    ClockDomain * clk_domain;
    unsigned clk_divider;
};

#endif // __PARAMS__DerivedClockDomain__
