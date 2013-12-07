#ifndef __PARAMS__X86SMBiosBiosInformation__
#define __PARAMS__X86SMBiosBiosInformation__

namespace X86ISA {
namespace SMBios {
class BiosInformation;
} // namespace SMBios
} // namespace X86ISA

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <vector>
#include "enums/Characteristic.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <vector>
#include "enums/ExtCharacteristic.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/X86SMBiosSMBiosStructure.hh"

#include "enums/Characteristic.hh"

#include "enums/ExtCharacteristic.hh"

struct X86SMBiosBiosInformationParams
    : public X86SMBiosSMBiosStructureParams
{
    X86ISA::SMBios::BiosInformation * create();
    uint8_t rom_size;
    std::string vendor;
    std::vector< Enums::Characteristic > characteristics;
    std::string release_date;
    uint8_t emb_cont_firmware_major;
    uint8_t major;
    uint8_t emb_cont_firmware_minor;
    std::string version;
    std::vector< Enums::ExtCharacteristic > characteristic_ext_bytes;
    uint16_t starting_addr_segment;
    uint8_t minor;
};

#endif // __PARAMS__X86SMBiosBiosInformation__
