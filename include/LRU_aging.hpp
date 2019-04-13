///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019  Nikunj Gupta
///////////////////////////////////////////////////////////////////////////////

#ifndef AGING
#define AGING

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
        class Aging: public Least_recently_used
        {
        public:
            // Default constructors
            Aging() = default;

            Aging(std::initializer_list<int> processes, int size)
            {
                for(auto&& process: processes)
                    incoming_process.push_back(process);
                
                page_table_size = size;

                // frames = processes.size();
            }

            void simulate();
        
        private:
            // Aging implementation
            std::vector<std::pair<int, long long>> page_table;
            std::vector<int> incoming_process;
            int frames;

            // Benchmarking tool
            tools::Benchmark init;
        };

        void Aging::simulate()
        {
            for(auto process: incoming_process)
            {
                long long reference = 1 << frames;

                if(page_table.size() < page_table_size)
                {
                    // Search for the process in the page table
                    auto it = std::find_if(page_table.begin(),
                                        page_table.end(),
                                        util::Search(process));
                                    
                    if(it != page_table.end())
                    // Process exists as a page table entry
                    {
                        // Update the process counter to the current counter value
                        (*it).second = (*it).second >> 1;
                        (*it).second += reference;

                        for(auto a = page_table.begin(); a != page_table.end(); ++a)
                        {
                            if(a != it)
                                (*a).second = (*a).second >> 1;
                        }

                        // Sort the page table according to counter values
                        std::sort(page_table.begin(), page_table.end(), util::Min);
                    }
                    else
                    // Process not found in the page table
                    {
                        for(auto a = page_table.begin(); a != page_table.end(); ++a)
                        {
                            (*a).second = (*a).second >> 1;
                        }

                        page_table.push_back(std::make_pair(process, reference));

                        // Increase number of page faults
                        init.page_faults++;

                        std::sort(page_table.begin(), page_table.end(), util::Min);
                    }
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
                        (*it).second = (*it).second >> 1;
                        (*it).second += reference;

                        for(auto a = page_table.begin(); a != page_table.end(); ++a)
                        {
                            if(a != it)
                                (*a).second = (*a).second >> 1;
                        }

                        // Sort the page table according to counter values
                        std::sort(page_table.begin(), page_table.end(), util::Min);
                    }
                    else
                    // Process not found in the page table
                    {
                        // Update the first process in page table
                        // with the incoming process.
                        page_table[0] = std::make_pair(process, reference);

                        for(auto a = page_table.begin() + 1; a != page_table.end(); ++a)
                        {
                            if(a != it)
                                (*a).second = (*a).second >> 1;
                        }

                        // Increase the page fault number due to page miss
                        init.page_faults++;

                        // Sort the page table according to counter values
                        std::sort(page_table.begin(), page_table.end(), util::Min);
                    }
                }
            }

            std::cout << "Number of page frames: " << page_table_size
                      << "\nNumber of page faults: " << init.page_faults
                      << std::endl;
        }
    }
}

#endif /* AGING */