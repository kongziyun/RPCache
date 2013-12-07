#ifndef __PARAMS__X86PagetableWalker__
#define __PARAMS__X86PagetableWalker__

namespace X86ISA {
class Walker;
} // namespace X86ISA

#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/MemObject.hh"

struct X86PagetableWalkerParams
    : public MemObjectParams
{
    X86ISA::Walker * create();
    System * system;
    unsigned num_squash_per_cycle;
    unsigned int port_port_connection_count;
};

#endif // __PARAMS__X86PagetableWalker__
