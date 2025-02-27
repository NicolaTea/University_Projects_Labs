//
// Created by Admin on 4/9/2024.
//

#ifndef LAB4_FRUITCONTROLLER_H
#define LAB4_FRUITCONTROLLER_H
#include <string>
#include<vector>
#include "../Repository/FruitRepostory.h"
#include"../Domain/Fruit.h"
using namespace std;
class FruitController {
private:
    FruitRepository* repo;
public:
    FruitController(FruitRepository* repository) ;
    void Add_UpdateFruit(const Fruit& fruit);
    void Remove_Fruit(const std::string& name, const std::string& origin);
    void List_Fruits_Containing(const std::string& search) const;
    void List_Low_Stock_Fruits(int level) const;
    void List_Fruits_SortedByExpirationDate() const;
    std::vector<Fruit> get_Inventory();
};

#endif //LAB4_FRUITCONTROLLER_H
