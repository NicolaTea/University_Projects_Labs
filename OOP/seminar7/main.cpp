#include <iostream>
#include "Navigator.h"
#include "BusStrategy.h"
#include "WalkStrategy.h"
#include "Vehicle.h"
#include "VehicleTableRowAdapter.h"

using namespace std;

int main() {
    RouteStrategy *strategy1 = new BusStrategy;
    Navigator nav(strategy1);
    nav.buildRoute().display();

    RouteStrategy *strategy2 = new WalkStrategy;
    nav.setStrategy(strategy2);
    nav.buildRoute().display();

    Vehicle v1(1, "Mercedes", "C-Class");
    VehicleTableRowAdapter rowAdt;
    vector<string> row = rowAdt.transform(v1);
    for (int i = 0; i < row.size(); i++) {
        cout << row[i] << '\n';
    }

    return 0;
}
