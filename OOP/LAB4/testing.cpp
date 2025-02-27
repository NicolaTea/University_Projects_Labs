//
// Created by Admin on 4/9/2024.
//
#include <cassert>
#include "Repository/FruitRepostory.h"
#include "Controller/FruitController.h"

void test_add_update_product() {
    FruitRepository repo;
    FruitController controller(&repo);

    Fruit fruit1("Apple", "USA", "2024-04-09", 100, 25);
    Fruit fruit2("Banana", "Ecuador", "2024-04-09", 150, 18);

    controller.Add_UpdateFruit(fruit1);
    controller.Add_UpdateFruit(fruit2);


    assert(repo.get_contain("Apple").size() == 1);
    assert(repo.get_contain("Banana").size() == 1);
}

void test_remove_product() {
    FruitRepository repo;
    FruitController controller(&repo);

    Fruit fruit1("Apple", "USA", "2024-04-09", 100, 25);
    Fruit fruit2("Banana", "Ecuador", "2024-04-09", 150, 18);

    controller.Add_UpdateFruit(fruit1);
    controller.Add_UpdateFruit(fruit2);

    controller.Remove_Fruit("Apple", "USA");


    assert(repo.get_contain("Apple").empty());
}



int main() {
    test_add_update_product();
    test_remove_product();
    std::cout << "Alle Tests erfolgreich durchgefuhrt!" << std::endl;

    return 0;
}