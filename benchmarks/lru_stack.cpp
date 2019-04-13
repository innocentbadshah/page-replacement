///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019  Nikunj Gupta
///////////////////////////////////////////////////////////////////////////////

#include "../include/LRU_stack.hpp"

int main(int argc, char* argv[])
{
    // Simulating LRU Stack requires you to add number of frames and the
    // incoming processes order.
    page_replacement::lru::Stack stack1({1,2,6,3,1,5,4,1,2,5,1,6,3,2,5,3,6,4,1,5}, 2);
    page_replacement::lru::Stack stack2({1,2,6,3,1,5,4,1,2,5,1,6,3,2,5,3,6,4,1,5}, 3);
    page_replacement::lru::Stack stack3({1,2,6,3,1,5,4,1,2,5,1,6,3,2,5,3,6,4,1,5}, 4);
    page_replacement::lru::Stack stack4({1,2,6,3,1,5,4,1,2,5,1,6,3,2,5,3,6,4,1,5}, 5);

    // Simulate with LRU algorithm with stack implementation
    stack1.simulate();
    stack2.simulate();
    stack3.simulate();
    stack4.simulate();

    return 0;
}