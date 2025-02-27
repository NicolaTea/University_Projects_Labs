cmake_minimum_required(VERSION 3.27)
project(MultiMaplab2)

set(CMAKE_CXX_STANDARD 23)

add_executable(MultiMaplab2
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        MultiMap.cpp
        MultiMap.h
        MultiMapIterator.cpp
        MultiMapIterator.h)
