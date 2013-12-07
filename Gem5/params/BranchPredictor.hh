#ifndef __PARAMS__BranchPredictor__
#define __PARAMS__BranchPredictor__

class BPredUnit;

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
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct BranchPredictorParams
    : public SimObjectParams
{
    BPredUnit * create();
    unsigned choiceCtrBits;
    unsigned globalCtrBits;
    unsigned numThreads;
    unsigned choicePredictorSize;
    unsigned instShiftAmt;
    unsigned localCtrBits;
    unsigned BTBTagSize;
    unsigned BTBEntries;
    unsigned localHistoryTableSize;
    unsigned localPredictorSize;
    std::string predType;
    unsigned RASSize;
    unsigned globalPredictorSize;
};

#endif // __PARAMS__BranchPredictor__
