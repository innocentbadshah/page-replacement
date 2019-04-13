///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019  Nikunj Gupta
///////////////////////////////////////////////////////////////////////////////

#ifndef UTIL
#define UTIL

#include <utility>

namespace util
{
    class Min
    {
    public:
        bool operator()(std::pair<int, int> a, std::pair<int, int> b)
        {
            return a.second > b.second;
        }
    };
} // util


#endif /* UTIL */