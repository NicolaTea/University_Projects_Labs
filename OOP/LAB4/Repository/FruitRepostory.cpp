//
// Created by Admin on 4/9/2024.
//
#include <algorithm>
#include "FruitRepostory.h"
bool compareExpDate(const Fruit& a, const Fruit& b) { //functie de compare
    return a.get_expiration_date() < b.get_expiration_date();
}

void FruitRepository::add_update(const Fruit &fruit1) {
    for (auto& f : fruits) {
        if (f.get_name() == fruit1.get_name() && f.get_origin() == fruit1.get_origin()) {

            f.set_quantity(fruit1.get_quantity()); //schimbam doar cantitatea
            //f.set_price(fruit1.get_price());
            return;
        }
    }

    fruits.push_back(fruit1); //daca nu este gasit fructul il adaugam
}


void FruitRepository::remove(const std::string& name, const std::string& origin) {
    for (auto it = fruits.begin(); it != fruits.end(); it++) { //iteram prin fruits
        if (it->get_name() == name && it->get_origin() == origin) { //stergem dupa nume si origine fructul cautat
            fruits.erase(it);
            return;
        }
    }
}

std::vector<Fruit> FruitRepository::get_all() const {
    return fruits;
}

std::vector<Fruit> FruitRepository::get_contain(const std::string& search) const {
    std::vector<Fruit> result;
    for (const auto& fruit : fruits) {
        if (fruit.get_name().find(search) != std::string::npos || fruit.get_origin().find(search) != std::string::npos) {
            result.push_back(fruit);
        }
    }
    return result;
}
//std::string::npos-valoare constanta care este returnata daca fct find nu a gasit sirul cautat
// npos-no position

std::vector<Fruit> FruitRepository::low_stock_Fruits(int level) const {
    std::vector<Fruit> result;
    for (const auto& fruit : fruits) {
        if (fruit.get_quantity() < level) {
            result.push_back(fruit);
        }
    }
    return result;
}

std::vector<Fruit> FruitRepository::sort_by_expDate() const { //sortare dupa functia de compare
    std::vector<Fruit> sortedFruits = fruits;
    std::sort(sortedFruits.begin(), sortedFruits.end(), compareExpDate);
    return sortedFruits;
}





