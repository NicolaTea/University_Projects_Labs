//
// Created by Admin on 6/1/2024.
//

#ifndef SEMINAR7_NAVIGATOR_H
#define SEMINAR7_NAVIGATOR_H


#include "Navigator.h"
#include "RouteStrategy.h"

class Navigator {
private:
    RouteStrategy *routeStrategy;
public:
    explicit Navigator(RouteStrategy *strategy);

    Route buildRoute();

    void setStrategy(RouteStrategy *strategy);

};



#endif //SEMINAR7_NAVIGATOR_H
