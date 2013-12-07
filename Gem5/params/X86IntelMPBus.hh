#ifndef __PARAMS__X86IntelMPBus__
#define __PARAMS__X86IntelMPBus__

namespace X86ISA {
namespace IntelMP {
class Bus;
} // namespace IntelMP
} // namespace X86ISA

#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"

#include "params/X86IntelMPBaseConfigEntry.hh"

struct X86IntelMPBusParams
    : public X86IntelMPBaseConfigEntryParams
{
    X86ISA::IntelMP::Bus * create();
    std::string bus_type;
    uint8_t bus_id;
};

#endif // __PARAMS__X86IntelMPBus__
