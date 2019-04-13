///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019  Nikunj Gupta
///////////////////////////////////////////////////////////////////////////////

#include "../include/clock.hpp"

int main(int argc, char* argv[])
{
    // Simulating clock requires you to add number of frames and the
    // incoming processes order.
    page_replacement::Clock clock1({2,5,10,1,2,2,6,9,1,2,10,2,6,1,2,1,6,9,5,1}, 2);
    page_replacement::Clock clock2({2,5,10,1,2,2,6,9,1,2,10,2,6,1,2,1,6,9,5,1}, 3);
    page_replacement::Clock clock3({2,5,10,1,2,2,6,9,1,2,10,2,6,1,2,1,6,9,5,1}, 4);
    page_replacement::Clock clock4({2,5,10,1,2,2,6,9,1,2,10,2,6,1,2,1,6,9,5,1}, 5);

    // Simulate with clock algorithm
    clock1.simulate();
    clock2.simulate();
    clock3.simulate();
    clock4.simulate();

    return 0;
}