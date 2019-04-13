///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019  Nikunj Gupta
///////////////////////////////////////////////////////////////////////////////

#ifndef UTIL
#define UTIL

#include <utility>

namespace util
{
    bool Min(std::pair<int, int> a, std::pair<int, int> b)
    {
        return a.second < b.second;
    }

    class Search
    {
    public:
        int val;

        Search(int v) :val(v) {}

        bool operator()(const std::pair<int, int> a) const
        {
            return (a.first == val);
        }
    };
} // util


#endif /* UTIL */