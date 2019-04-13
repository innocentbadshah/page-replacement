///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019  Nikunj Gupta
///////////////////////////////////////////////////////////////////////////////

#include "../include/clock.hpp"

int main(int argc, char* argv[])
{
    // Simulating clock requires you to add number of frames and the
    // incoming processes order.
    page_replacement::Clock clock({0,4,1,5,2,4,3,5,2,4,0,5,1,4,2,5,3,4}, 4);

    // Simulate with clock algorithm
    clock.simulate();

    return 0;
}