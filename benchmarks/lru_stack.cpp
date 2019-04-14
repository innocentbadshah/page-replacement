///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019  Nikunj Gupta
///////////////////////////////////////////////////////////////////////////////

#include "../include/LRU_stack.hpp"

int main(int argc, char* argv[])
{
    // Simulating LRU counter requires you to add number of frames and the
    // incoming processes order.
    page_replacement::lru::Stack stack({1,2,3,4,1,2,5,1,2,3,4,5}, 4);

    // Simulate with LRU algorithm with counter implementation
    stack.simulate();

    return 0;
}