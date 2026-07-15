//
// Created by Admin on 6/1/2024.
//

#ifndef SEMINAR7_WALKSTRATEGY_H
#define SEMINAR7_WALKSTRATEGY_H


#include "RouteStrategy.h"

class WalkStrategy : public RouteStrategy {
public:
    Route buildRoute() override;

};



#endif //SEMINAR7_WALKSTRATEGY_H
