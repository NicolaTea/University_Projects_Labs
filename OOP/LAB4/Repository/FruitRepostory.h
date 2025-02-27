//
// Created by Admin on 4/9/2024.
//

#ifndef LAB4_FRUITREPOSTORY_H
#define LAB4_FRUITREPOSTORY_H
#include<vector>
#include<iostream>
using namespace std;
#include"../Domain//Fruit.h"
class FruitRepository {
private:
    vector <Fruit> fruits;
public:
    vector <Fruit> get_contain(const string &search) const;
    std::vector<Fruit> low_stock_Fruits(int level) const;
    std::vector<Fruit> sort_by_expDate() const;
    //practic doar astea trebuie
    void add_update(const Fruit &fruit1);
    std::vector<Fruit> get_all() const;
    void remove(const std::string &name, const std::string &origin);


};



#endif //LAB4_FRUITREPOSTORY_H
