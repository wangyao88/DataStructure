cmake_minimum_required(VERSION 3.16)
project(demo)

set(CMAKE_CXX_STANDARD 20)

add_executable(demo main.cpp 1_lineList/sequenceLine.h 1_lineList/singleChainLine.h 1_lineList/cycleDouble/CycleDoubleChainLine.h 1_lineList/cycleDouble/CycleDoubleChainLine.cpp 1_lineList/cycleSingle/CycleSingleChainLine.h)