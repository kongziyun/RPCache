#ifndef __PARAMS__X86IntelMPIOAPIC__
#define __PARAMS__X86IntelMPIOAPIC__

namespace X86ISA {
namespace IntelMP {
class IOAPIC;
} // namespace IntelMP
} // namespace X86ISA

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/X86IntelMPBaseConfigEntry.hh"

struct X86IntelMPIOAPICParams
    : public X86IntelMPBaseConfigEntryParams
{
    X86ISA::IntelMP::IOAPIC * create();
    uint8_t id;
    bool enable;
    uint8_t version;
    uint32_t address;
};

#endif // __PARAMS__X86IntelMPIOAPIC__
