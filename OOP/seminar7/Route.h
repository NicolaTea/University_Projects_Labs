//
// Created by Admin on 6/1/2024.
//

#ifndef SEMINAR7_ROUTE_H
#define SEMINAR7_ROUTE_H


#include <iostream>

class Route {
private:
    std::string type;
public:
    explicit Route(std::string type);

    void display() const;

};


#endif //SEMINAR7_ROUTE_H
