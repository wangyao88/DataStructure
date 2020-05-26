cmake_minimum_required(VERSION 3.16)
project(demo)

set(CMAKE_CXX_STANDARD 20)

add_executable(demo main.cpp 1_lineList/sequenceLine.h 1_lineList/singleChainLine.h 1_lineList/cycleDouble/CycleDoubleChainLine.h
        1_lineList/cycleDouble/CycleDoubleChainLine.cpp 1_lineList/cycleSingle/CycleSingleChainLine.h
        1_lineList/cycleSingle/CycleSingleChainLine.cpp
        2_stack/SequentialStack.h 2_stack/SequentialStack.cpp
        3_queue/CycleQueue.h 3_queue/CycleQueue.cpp 3_queue/LinkQueue.h 3_queue/LinkQueue.cpp)