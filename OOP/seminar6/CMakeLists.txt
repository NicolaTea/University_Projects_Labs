cmake_minimum_required(VERSION 3.27)
project(seminar6)

set(CMAKE_CXX_STANDARD 23)

add_executable(seminar6 main.cpp
        Client.h
        CRUD_Repository.h
        ClientInMemory.cpp
        ClientController.cpp
        Vehicle.h
        CLR2.h
        CLR2.cpp)
