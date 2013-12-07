#ifndef __PARAMS__SeriesRequestGenerator__
#define __PARAMS__SeriesRequestGenerator__

class SeriesRequestGenerator;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/DirectedGenerator.hh"

struct SeriesRequestGeneratorParams
    : public DirectedGeneratorParams
{
    SeriesRequestGenerator * create();
    int percent_writes;
    uint32_t num_series;
    int addr_increment_size;
};

#endif // __PARAMS__SeriesRequestGenerator__
