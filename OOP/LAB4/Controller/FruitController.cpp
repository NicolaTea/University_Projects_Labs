//
// Created by Admin on 4/9/2024.
//
#include <algorithm>
#include "FruitController.h"



FruitController::FruitController(FruitRepository *repository) {
    repo=repository;
}
void FruitController::Add_UpdateFruit(const Fruit& fruit) {
    repo->add_update(fruit);
}

void FruitController::Remove_Fruit(const std::string& name, const std::string& origin) {
    repo->remove(name, origin);
}

void FruitController::List_Fruits_Containing(const std::string& search) const {
    vector<Fruit> fruits = repo->get_contain(search);
    for (const auto& fruit : fruits) {
        cout << fruit.get_name() << " from " << fruit.get_origin() << "\n";
    }
}

void FruitController::List_Low_Stock_Fruits(int level) const {
    vector<Fruit> fruits = repo->low_stock_Fruits(level);
    for (const auto& fruit : fruits) {
        cout << fruit.get_name() << " - Quantity: " <<fruit.get_quantity() << "\n";
    }
}

void FruitController::List_Fruits_SortedByExpirationDate() const {
    vector<Fruit> fruits = repo->sort_by_expDate();
    for (const auto& fruit : fruits) {
        cout << fruit.get_name() << " - Expiration Date: " << fruit.get_expiration_date() << "\n";
    }
}

std::vector<Fruit> FruitController::get_Inventory() {
    return repo->get_all();
}