//
// Created by Admin on 6/1/2024.
//

#ifndef SEMINAR7_VEHICLE_H
#define SEMINAR7_VEHICLE_H

#include<string>

using namespace std;

class Vehicle {
private:
    int id;
    string brand;
    string model;
public:

    Vehicle(int id, const string &brand, const string &model);

    int getId() const;

    const string &getBrand() const;

    const string &getModel() const;

};


#endif //SEMINAR7_VEHICLE_H
