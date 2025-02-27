cmake_minimum_required(VERSION 3.27)
project(LAB4)

set(CMAKE_CXX_STANDARD 23)

# Application
add_executable(LAB4
        Shop.cpp
        Domain/Fruit.cpp
        Repository/FruitRepostory.cpp
        Controller/FruitController.cpp
        UI/FruitUi.cpp
)

# Tests
add_executable(Tests
        testing.cpp
        Domain/Fruit.cpp
        Repository/FruitRepostory.cpp
        Controller/FruitController.cpp
        UI/FruitUi.cpp)