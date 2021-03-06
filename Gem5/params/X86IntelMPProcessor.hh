#ifndef __PARAMS__X86IntelMPProcessor__
#define __PARAMS__X86IntelMPProcessor__

namespace X86ISA {
namespace IntelMP {
class Processor;
} // namespace IntelMP
} // namespace X86ISA

#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/X86IntelMPBaseConfigEntry.hh"

struct X86IntelMPProcessorParams
    : public X86IntelMPBaseConfigEntryParams
{
    X86ISA::IntelMP::Processor * create();
    bool enable;
    uint8_t local_apic_version;
    uint8_t family;
    bool bootstrap;
    uint32_t feature_flags;
    uint8_t stepping;
    uint8_t model;
    uint8_t local_apic_id;
};

#endif // __PARAMS__X86IntelMPProcessor__
