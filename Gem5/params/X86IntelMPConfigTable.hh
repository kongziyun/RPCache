#ifndef __PARAMS__X86IntelMPConfigTable__
#define __PARAMS__X86IntelMPConfigTable__

namespace X86ISA {
namespace IntelMP {
class ConfigTable;
} // namespace IntelMP
} // namespace X86ISA

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <vector>
#include "params/X86IntelMPExtConfigEntry.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "params/X86IntelMPBaseConfigEntry.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct X86IntelMPConfigTableParams
    : public SimObjectParams
{
    X86ISA::IntelMP::ConfigTable * create();
    uint32_t oem_table_addr;
    std::string product_id;
    std::vector< X86ISA::IntelMP::ExtConfigEntry * > ext_entries;
    uint8_t spec_rev;
    std::vector< X86ISA::IntelMP::BaseConfigEntry * > base_entries;
    std::string oem_id;
    uint32_t local_apic;
    uint16_t oem_table_size;
};

#endif // __PARAMS__X86IntelMPConfigTable__
