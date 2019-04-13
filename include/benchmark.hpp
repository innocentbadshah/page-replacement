///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019  Nikunj Gupta
///////////////////////////////////////////////////////////////////////////////

#ifndef BENCHMARK
#define BENCHMARK

#include <memory>

namespace tools
{
    class Benchmark
    {
    public:
        // Number of page_faults
        int page_faults = 0;
        Benchmark() = default;
    };
}

#endif /* BENCHMARK */