cmake_minimum_required(VERSION 3.27)
project(seminar7)

set(CMAKE_CXX_STANDARD 23)

add_executable(seminar7 main.cpp
        BusStrategy.cpp
        BusStrategy.h
        Navigator.cpp
        Navigator.h
        RoadStrategy.cpp
        RoadStrategy.h
        Route.cpp
        Route.h
        RouteStrategy.cpp
        RouteStrategy.h
        TableRowAdapter.cpp
        TableRowAdapter.h
        Vehicle.cpp
        Vehicle.h
        VehicleTableRowAdapter.cpp
        VehicleTableRowAdapter.h
        WalkStrategy.cpp
        WalkStrategy.h)
