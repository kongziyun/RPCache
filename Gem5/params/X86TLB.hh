#ifndef __PARAMS__X86TLB__
#define __PARAMS__X86TLB__

namespace X86ISA {
class TLB;
} // namespace X86ISA

#include <cstddef>
#include "params/X86PagetableWalker.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BaseTLB.hh"

struct X86TLBParams
    : public BaseTLBParams
{
    X86ISA::TLB * create();
    X86ISA::Walker * walker;
    int size;
};

#endif // __PARAMS__X86TLB__
