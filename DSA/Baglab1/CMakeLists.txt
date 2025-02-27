cmake_minimum_required(VERSION 3.27)
project(Baglab1)

set(CMAKE_CXX_STANDARD 23)

add_executable(Baglab1
        App.cpp
        ExtendedTest.cpp
        ShortTest.cpp
        ExtendedTest.h
        ShortTest.h
        Bag.cpp
        BagIterator.cpp
        Bag.h
        BagIterator.h)
