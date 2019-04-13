///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019  Nikunj Gupta
///////////////////////////////////////////////////////////////////////////////

#include "../include/LRU_counter.hpp"

int main(int argc, char* argv[])
{
    // Simulating LRU counter requires you to add number of frames and the
    // incoming processes order.
    page_replacement::lru::Counter counter1({0,3,1,3,2,3,6,0,4,1,4,2,4,7,0,5,1,2,5,8,0,3,1,3}, 2);
    page_replacement::lru::Counter counter2({0,3,1,3,2,3,6,0,4,1,4,2,4,7,0,5,1,2,5,8,0,3,1,3}, 3);
    page_replacement::lru::Counter counter3({0,3,1,3,2,3,6,0,4,1,4,2,4,7,0,5,1,2,5,8,0,3,1,3}, 4);
    page_replacement::lru::Counter counter4({0,3,1,3,2,3,6,0,4,1,4,2,4,7,0,5,1,2,5,8,0,3,1,3}, 5);
    page_replacement::lru::Counter counter5({0,3,1,3,2,3,6,0,4,1,4,2,4,7,0,5,1,2,5,8,0,3,1,3}, 6);

    // Simulate with LRU algorithm with counter implementation
    counter1.simulate();
    counter2.simulate();
    counter3.simulate();
    counter4.simulate();
    counter5.simulate();

    return 0;
}