///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019  Nikunj Gupta
///////////////////////////////////////////////////////////////////////////////

#ifndef CLOCK
#define CLOCK

#include "./util.hpp"
#include "./benchmark.hpp"

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

namespace page_replacement
{
    class Clock
    {
    public:
        // Default constructors
        Clock() = default;
        Clock(std::initializer_list<int> processes, int size)
        {
            for(auto&& process: processes)
                    incoming_process.push_back(process);
            
            page_table_size = size;
            // frames = processes.size();

        }

        // Simulate function
        void simulate();

        bool find_and_update(int);

        int replace(int);

    private:
        std::vector<int> incoming_process;
        int page_table_size;
        // int frames;

        int pointer = 0;
        std::vector<int> page_table;
        std::vector<bool> second_chance;

        // Benchmarking tool
        tools::Benchmark init;
    };

    bool Clock::find_and_update(int process)
    {
        for(auto i = 0; i < page_table.size(); ++i)
        {
            if(page_table[i] == process)
            // Page found in the page table
            {
                // Mark this page for second chance
                second_chance[i] = true;

                // Return a hit
                return true;
            }
        }

        // Return a miss
        return false;
    }

    int Clock::replace(int process)
    {
        while(true)
        {
            if(!second_chance[pointer])
            // Page to replace
            {
                page_table[pointer] = process;

                // Update pointer to next element
                return (pointer + 1) % page_table_size;
            }

            // No second chance, unless found in the next iteration
            second_chance[pointer] = false;

            pointer = (pointer + 1) % page_table_size;
        }
    }

    void Clock::simulate()
    {
        // Initialize page table and second chance
        for(auto i = 0; i < page_table_size; ++i)
        {
            page_table.push_back(-1);
            second_chance.push_back(false);
        }

        // Actual implementation
        for(auto process: incoming_process)
        {
            if(!find_and_update(process))
            {
                pointer = replace(process);

                init.page_faults++;
            }
        }

        std::cout << "Number of frames: " << page_table_size
                  << "\nNumber of page faults: " << init.page_faults
                  << std::endl;
    }
}

#endif /* CLOCK */