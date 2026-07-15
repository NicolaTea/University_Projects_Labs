//
// Created by Admin on 6/1/2024.
//

#include "Navigator.h"
#include "RouteStrategy.h"
#include "Navigator.h"

Navigator::Navigator(RouteStrategy *strategy) : routeStrategy(strategy) {}

Route Navigator::buildRoute() {
    return routeStrategy->buildRoute();
}

void Navigator::setStrategy(RouteStrategy *strategy) {
    Navigator::routeStrategy = strategy;
}