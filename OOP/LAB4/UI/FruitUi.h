//
// Created by Admin on 4/9/2024.
//

#ifndef LAB4_FRUITUI_H
#define LAB4_FRUITUI_H
#include<iostream>
#include"../Controller/FruitController.h"

class FruitUI {
private:
    FruitController* ctrl;
public:
    FruitUI(FruitController* ctrl) : ctrl(ctrl) {}
    void run();
    void displayInventory();
};



#endif //LAB4_FRUITUI_H
