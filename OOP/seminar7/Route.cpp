//
// Created by Admin on 6/1/2024.
//

#include "Route.h"
#include "Route.h"

void Route::display() const {
    std::cout << "Route strategy: " << type << std::endl;
}

Route::Route(std::string type) : type(type) {}
