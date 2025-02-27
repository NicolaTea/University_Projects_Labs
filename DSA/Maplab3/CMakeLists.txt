cmake_minimum_required(VERSION 3.27)
project(Maplab3)

set(CMAKE_CXX_STANDARD 23)

add_executable(Maplab3
        Map.cpp
        Map.h
        MapIterator.cpp
        MapIterator.h
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h)
add_executable(testing test.cpp)