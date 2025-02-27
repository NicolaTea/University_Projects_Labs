cmake_minimum_required(VERSION 3.27)
project(LAB2)

set(CMAKE_CXX_STANDARD 23)

add_executable(LAB2 main.cpp
        L2_Nicola_Tea_Problem0_length.cpp
        L2_Nicola_Tea_Problem0_length.h)
add_executable( testing L2_Nicola_Tea_Problem0_length_test.cpp)
