cmake_minimum_required(VERSION 3.27)
project(Setlab4)

set(CMAKE_CXX_STANDARD 23)

add_executable(Setlab4
        Set.cpp
        Set.h
        SetIterator.cpp
        SetIterator.h
        ShortTest.cpp
        ShortTest.h
        ExtendedTest.cpp
        ExtendedTest.h
        App.cpp
        test.cpp)
