cmake_minimum_required(VERSION 3.27)
project(PriorityQueuelab5)

set(CMAKE_CXX_STANDARD 23)

add_executable(PriorityQueuelab5
        PriorityQueue.cpp
        PriorityQueue.h
        ExtendedTest.cpp
        ExtendedTest.h
        App.cpp
        ShortTest.cpp
        ShortTest.h)
