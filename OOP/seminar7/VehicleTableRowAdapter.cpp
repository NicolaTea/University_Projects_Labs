//
// Created by Admin on 6/1/2024.
//

#include "VehicleTableRowAdapter.h"

vector<string> VehicleTableRowAdapter::transform(Vehicle &vehicle) {
    vector<string> row;
    row.push_back(to_string(vehicle.getId()));
    row.push_back(vehicle.getBrand());
    row.push_back(vehicle.getModel());
    return row;
}

