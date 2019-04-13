///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019  Nikunj Gupta
///////////////////////////////////////////////////////////////////////////////

#ifndef COUNTER
#define COUNTER

#include "./LRU.hpp"
#include "./util.hpp"
#include "./benchmark.hpp"

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

namespace page_replacement
{
    namespace lru
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
            std::vector<std::pair<int, int>> page_table;
            std::vector<int> incoming_process;

            // Benchmarking tool
            tools::Benchmark init;
        };

        void Counter::simulate()
        {
            // Global counter keeping track of time
            int counter = 1;

            for(auto process: incoming_process)
            {
                if(page_table.size() < page_table_size)
                {
                    page_table.push_back(std::make_pair(process, counter));

                    // Increase number of page faults
                    init.page_faults++;

                    std::sort(page_table.begin(), page_table.end(), util::Min);
                }
                else
                {
                    // Search for the process in the page table
                    auto it = std::find_if(page_table.begin(),
                                        page_table.end(),
                                        util::Search(process));

                    if(it != page_table.end())
                    // Process exists as a page table entry
                    {
                        // Update the process counter to the current counter value
                        (*it).second = counter;

                        // Sort the page table according to counter values
                        std::sort(page_table.begin(), page_table.end(), util::Min);
                    }
                    else
                    // Process not found in the page table
                    {
                        // Update the first process in page table
                        // with the incoming process.
                        page_table[0] = std::make_pair(process, counter);

                        // Increase the page fault number due to page miss
                        init.page_faults++;

                        // Sort the page table according to counter values
                        std::sort(page_table.begin(), page_table.end(), util::Min);
                    }
                }

                // Increase counter
                counter++;
            }

            std::cout << "Number of page frames: " << page_table_size
                      << "\nNumber of page faults: " << init.page_faults
                      << std::endl;
        }

    } // LRU
    
} // page_replacement


#endif /* COUNTER */