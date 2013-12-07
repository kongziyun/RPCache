#ifndef __PARAMS__PciDevice__
#define __PARAMS__PciDevice__

class PciDev;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
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
#include <cstddef>
#include "params/Platform.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
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

#include "params/DmaDevice.hh"

struct PciDeviceParams
    : public DmaDeviceParams
{
    uint16_t VendorID;
    uint8_t InterruptPin;
    uint8_t HeaderType;
    int pci_dev;
    uint32_t BAR5Size;
    uint16_t SubsystemID;
    uint32_t CardbusCIS;
    uint8_t MinimumGrant;
    uint8_t Revision;
    uint16_t Status;
    uint8_t MaximumLatency;
    bool BAR2LegacyIO;
    uint32_t BAR0Size;
    Tick pio_latency;
    uint8_t LatencyTimer;
    bool BAR1LegacyIO;
    Platform * platform;
    bool BAR4LegacyIO;
    uint16_t SubsystemVendorID;
    uint32_t BAR3Size;
    bool BAR5LegacyIO;
    bool BAR0LegacyIO;
    uint16_t Command;
    uint16_t DeviceID;
    uint8_t ProgIF;
    uint8_t SubClassCode;
    int pci_func;
    uint32_t BAR4Size;
    uint32_t BAR1;
    uint32_t BAR0;
    uint32_t BAR3;
    uint32_t BAR2;
    uint32_t BAR5;
    uint32_t BAR4;
    uint8_t ClassCode;
    uint8_t BIST;
    uint8_t CacheLineSize;
    uint32_t BAR2Size;
    uint32_t ExpansionROM;
    bool BAR3LegacyIO;
    Tick config_latency;
    int pci_bus;
    uint8_t InterruptLine;
    uint32_t BAR1Size;
    unsigned int port_config_connection_count;
};

#endif // __PARAMS__PciDevice__
