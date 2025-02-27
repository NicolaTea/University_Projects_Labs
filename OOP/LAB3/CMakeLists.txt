cmake_minimum_required(VERSION 3.27)
project(LAB3)

set(CMAKE_CXX_STANDARD 23)

add_executable(LAB3 main.cpp
        L3_Nicola_Tea_DSM.cpp
        L3_Nicola_Tea_DSM.h)
add_executable(testing L3_Nicola_Tea_DSM_test.cpp)
