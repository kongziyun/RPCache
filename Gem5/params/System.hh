#ifndef __PARAMS__System__
#define __PARAMS__System__

class System;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include "enums/MemoryMode.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <vector>
#include "params/AbstractMemory.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/MemObject.hh"

#include "enums/MemoryMode.hh"

struct SystemParams
    : public MemObjectParams
{
    System * create();
    uint64_t load_addr_mask;
    std::string kernel;
    Enums::MemoryMode mem_mode;
    Counter work_end_ckpt_count;
    std::string boot_osflags;
    std::vector< AbstractMemory * > memories;
    Counter work_begin_ckpt_count;
    std::string symbolfile;
    uint64_t init_param;
    std::string readfile;
    int num_work_ids;
    Counter work_cpus_ckpt_count;
    std::vector< AddrRange > mem_ranges;
    int work_begin_cpu_id_exit;
    Counter work_end_exit_count;
    int work_item_id;
    Counter work_begin_exit_count;
    unsigned int port_system_port_connection_count;
};

#endif // __PARAMS__System__
