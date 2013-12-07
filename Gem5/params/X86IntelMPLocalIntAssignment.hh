#ifndef __PARAMS__X86IntelMPLocalIntAssignment__
#define __PARAMS__X86IntelMPLocalIntAssignment__

namespace X86ISA {
namespace IntelMP {
class LocalIntAssignment;
} // namespace IntelMP
} // namespace X86ISA

#include <cstddef>
#include "enums/X86IntelMPPolarity.hh"
#include <cstddef>
#include "enums/X86IntelMPInterruptType.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "enums/X86IntelMPTriggerMode.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/X86IntelMPBaseConfigEntry.hh"

#include "enums/X86IntelMPPolarity.hh"

#include "enums/X86IntelMPInterruptType.hh"

#include "enums/X86IntelMPTriggerMode.hh"

struct X86IntelMPLocalIntAssignmentParams
    : public X86IntelMPBaseConfigEntryParams
{
    X86ISA::IntelMP::LocalIntAssignment * create();
    Enums::X86IntelMPPolarity polarity;
    Enums::X86IntelMPInterruptType interrupt_type;
    uint8_t dest_local_apic_id;
    Enums::X86IntelMPTriggerMode trigger;
    uint8_t source_bus_id;
    uint8_t dest_local_apic_intin;
    uint8_t source_bus_irq;
};

#endif // __PARAMS__X86IntelMPLocalIntAssignment__
