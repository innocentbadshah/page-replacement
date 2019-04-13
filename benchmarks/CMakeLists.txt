cmake_minimum_required(VERSION 3.3.2)

project(lru_algorithms CXX)

set(tests
    lru_counter
)

foreach(test ${tests})
    add_executable(${test}
                   ${test}.cpp)
endforeach()