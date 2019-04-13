///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019  Nikunj Gupta
///////////////////////////////////////////////////////////////////////////////

#include "../include/LRU_aging.hpp"

int main(int argc, char* argv[])
{
    // Simulating LRU Aging requires you to add number of frames and the
    // incoming processes order.
    page_replacement::lru::Aging aging1({7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1}, 2);
    page_replacement::lru::Aging aging2({7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1}, 3);
    page_replacement::lru::Aging aging3({7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1}, 4);
    page_replacement::lru::Aging aging4({7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1}, 5);
    page_replacement::lru::Aging aging5({7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1}, 6);

    // Simulate with LRU algorithm with aging implementation
    aging1.simulate();
    aging2.simulate();
    aging3.simulate();
    aging4.simulate();
    aging5.simulate();

    return 0;
}