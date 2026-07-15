//
// Created by Admin on 6/1/2024.
//

#ifndef SEMINAR7_VEHICLETABLEROWADAPTER_H
#define SEMINAR7_VEHICLETABLEROWADAPTER_H

#include "Vehicle.h"
#include "TableRowAdapter.h"
#include <vector>
#include<string>
using namespace std;

class VehicleTableRowAdapter : public TableRowAdapter<Vehicle> {
public:
    vector<string> transform(Vehicle &vehicle) override;
};



#endif //SEMINAR7_VEHICLETABLEROWADAPTER_H
