#ifndef __PARAMS__SimpleMemory__
#define __PARAMS__SimpleMemory__

class SimpleMemory;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"

#include "params/AbstractMemory.hh"

struct SimpleMemoryParams
    : public AbstractMemoryParams
{
    SimpleMemory * create();
    Tick latency;
    float bandwidth;
    Tick latency_var;
    unsigned int port_port_connection_count;
};

#endif // __PARAMS__SimpleMemory__
