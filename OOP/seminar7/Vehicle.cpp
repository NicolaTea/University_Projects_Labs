//
// Created by Admin on 6/1/2024.
//

#include "Vehicle.h"

Vehicle::Vehicle(int id, const string &brand, const string &model) : id(id), brand(brand), model(model) {}

int Vehicle::getId() const {
    return id;
}

const string &Vehicle::getBrand() const {
    return brand;
}

const string &Vehicle::getModel() const {
    return model;
}

