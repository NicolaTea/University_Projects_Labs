//
// Created by Admin on 6/1/2024.
//

#ifndef SEMINAR7_BUSSTRATEGY_H
#define SEMINAR7_BUSSTRATEGY_H

#include "RouteStrategy.h"

class BusStrategy : public RouteStrategy {
public:
    Route buildRoute() override;
};


#endif //SEMINAR7_BUSSTRATEGY_H
