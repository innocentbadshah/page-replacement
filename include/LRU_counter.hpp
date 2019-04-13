///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019  Nikunj Gupta
///////////////////////////////////////////////////////////////////////////////

#ifndef COUNTER
#define COUNTER

#include "./LRU.hpp"
#include "./util.hpp"

#include <vector>
#include <queue>
#include <utility>

namespace page_replacement
{
    namespace LRU
    {
        class Counter: public Least_recently_used
        {
        public:
            // Default constructors
            Counter() = default;
            Counter(std::initializer_list<int> processes, int size)
            {
                for(auto&& process: processes)
                    incoming_process.push_back(process);
                
                page_table_size = size;
            }

            // Simulate function
            void simulate();

        private:
            // Counter to every Page
            std::priority_queue<std::pair<int, int>,
                    std::vector<std::pair<int, int>>,
                    util::Min> page_table;
            std::vector<int> incoming_process;

            // Benchmarking tool
            
        };

        void Counter::simulate()
        {

        }

    } // LRU
    
} // page_replacement


#endif /* COUNTER */