///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019  Nikunj Gupta
///////////////////////////////////////////////////////////////////////////////

#ifndef STACK
#define STACK

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
        class Stack: public Least_recently_used
        {
        public:
            // Default constructors
            Stack() = default;
            Stack(std::initializer_list<int> processes, int size)
            {
                for(auto&& process: processes)
                    incoming_process.push_back(process);
                
                page_table_size = size;

                frames = processes.size();

                page_table.init(page_table_size);
            }    

            // Simulate function
            void simulate();

        private:
            // Custom stack implementation for stack implementation
            util::stack page_table;
            std::vector<int> incoming_process;
            int frames;

            // Benchmarking tool
            tools::Benchmark init;
        };

        void Stack::simulate()
        {
            for(auto process: incoming_process)
            {
                if(page_table.get_size() < page_table_size)
                {
                    // Search for the process in the page table
                    int pos = page_table.find(process);

                    if(pos != -1)
                    {
                        page_table.update(process);
                    }
                    else
                    {
                        page_table.push(process);

                        // Increase number of page faults
                        init.page_faults++;
                    }
                }
                else
                {
                    // Search for the process in the page table
                    int pos = page_table.find(process);

                    if(pos != -1)
                    {
                        page_table.update(process);
                    }
                    else
                    {
                        // Push to the page table
                        page_table.push(process);

                        // Increase the page fault number due to page miss
                        init.page_faults++;
                    }
                }
            }

            std::cout << "Number of page frames: " << frames
                      << "\nNumber of page faults: " << init.page_faults
                      << std::endl;
        }
    }
}

#endif /* STACK */