//
// Created by Admin on 4/9/2024.
//

#include "Controller/FruitController.h"
#include "UI/FruitUi.h"
#include <memory>

int main() {
    FruitRepository repo;
    FruitController controller(&repo);
    FruitUI ui(&controller);
    Fruit f1("Apple", "USA", "2024-04-09", 30, 50);
    Fruit f2("Banana", "Ecuador", "2024-05-02", 75, 100);
    Fruit f3("Orange", "Spain", "2024-04-13", 46, 67);
    Fruit f4("Strawberry", "Mexico", "2024-06-18", 80, 100);
    Fruit f5("Watermelon", "Brazil", "2024-05-14", 90, 180);
    Fruit f6("Kiwi", "New Zealand", "2024-04-11", 56, 159);
    Fruit f7("Grapes", "Italy", "2024-04-22", 110, 200);
    Fruit f8("Pineapple", "Hawaii", "2024-05-07", 34, 89);
    Fruit f9("Peach", "Georgia", "2024-05-27", 95, 130);
    Fruit f10("Mango", "India", "2024-06-20", 140, 300);
    repo.add_update(f1);
    repo.add_update(f2);
    repo.add_update(f3);
    repo.add_update(f4);
    repo.add_update(f5);
    repo.add_update(f6);
    repo.add_update(f7);
    repo.add_update(f8);
    repo.add_update(f9);
    repo.add_update(f10);
    ui.run();
    return 0;
}
