#ifndef __PARAMS__X86IntelMPIOIntAssignment__
#define __PARAMS__X86IntelMPIOIntAssignment__

namespace X86ISA {
namespace IntelMP {
class IOIntAssignment;
} // namespace IntelMP
} // namespace X86ISA

#include <cstddef>
#include "enums/X86IntelMPPolarity.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "enums/X86IntelMPInterruptType.hh"
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

struct X86IntelMPIOIntAssignmentParams
    : public X86IntelMPBaseConfigEntryParams
{
    X86ISA::IntelMP::IOIntAssignment * create();
    Enums::X86IntelMPPolarity polarity;
    uint8_t dest_io_apic_id;
    Enums::X86IntelMPInterruptType interrupt_type;
    Enums::X86IntelMPTriggerMode trigger;
    uint8_t source_bus_id;
    uint8_t dest_io_apic_intin;
    uint8_t source_bus_irq;
};

#endif // __PARAMS__X86IntelMPIOIntAssignment__
