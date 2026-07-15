//
// Created by Admin on 6/1/2024.
//

#ifndef SEMINAR7_TABLEROWADAPTER_H
#define SEMINAR7_TABLEROWADAPTER_H


#include "Vehicle.h"
#include <vector>

template<typename A>
class TableRowAdapter {
    virtual vector<string> transform(A &vehicle) = 0;

};



#endif //SEMINAR7_TABLEROWADAPTER_H
