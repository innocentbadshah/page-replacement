///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019  Nikunj Gupta
///////////////////////////////////////////////////////////////////////////////

#ifndef LRU
#define LRU

namespace page_replacement
{
    // Base class for the LRU algorithm
    // All implementations of LRU algorithm will be derived from the following
    // class.
    class Least_recently_used
    {
    public:
        // Page table size
        int page_table_size;

        // Simulate function to simulate LRU algorithm
        virtual void simulate() = 0;
    };    
} // page_replacement

#endif /* LRU */
