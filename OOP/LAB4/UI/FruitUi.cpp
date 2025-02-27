//
// Created by Admin on 4/9/2024.
//

#include "FruitUi.h"
void FruitUI::run() {
    int choice = 0;
    while (choice != 7) {
        cout << "=== FruitMenu ===\n";
        cout << "1. Add or update fruit\n";
        cout << "2. Remove fruit\n";
        cout << "3. List fruits containing\n";
        cout << "4. List low stock fruits\n";
        cout << "5. List fruits sorted by expiration date\n";
        cout << "6. Display inventory\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {

                string name, origin, expirationDate;
                int quantity;
                int price;

                cout << "Enter fruit name: ";
                cin >> name;
                cout << "Enter fruit origin: ";
                cin >> origin;
                cout << "Enter fruit expiration date: ";
                cin >> expirationDate;
                cout << "Enter fruit price: ";
                cin >> price;
                cout << "Enter fruit cantitate: ";
                cin >> quantity;
                Fruit fruit{name, origin, expirationDate, price, quantity};
                ctrl->Add_UpdateFruit(fruit);
                break;
            }
            case 2: {
                string name, origin;
                cout << "Enter fruit name: ";
                cin >> name;
                cout << "Enter fruit origin: ";
                cin >> origin;
                ctrl->Remove_Fruit(name, origin);
                break;
            }
            case 3: {
                string searchString;
                cout << "Enter search string: ";
                cin >> searchString;
                ctrl->List_Fruits_Containing(searchString);
                break;
            }
            case 4: {
                int threshold;
                cout << "Enter threshold quantity: ";
                cin >> threshold;
                ctrl->List_Low_Stock_Fruits(threshold);
                break;
            }
            case 5: {
                ctrl->List_Fruits_SortedByExpirationDate();
                break;
            }
            case 6:{
                displayInventory();
                break;
            }
            case 7: {
                std::cout << "Exited\n";
                break;
            }
            default: {
                std::cout << "Invalid choice. Please enter a number between 1 and 7.\n";
                break;
            }
        }
    }
}



void FruitUI::displayInventory() {
    std::vector<Fruit> inventory = ctrl->get_Inventory();

    if (inventory.empty()) {
        std::cout << "Inventory is empty." << std::endl;
        return;
    }

    std::cout << "Inventory contains:" << std::endl;
    for (const auto& fruit : inventory) {
        std::cout << "Name: " << fruit.get_name() << ", Origin: " << fruit.get_origin()
                  << ", Quantity: " << fruit.get_quantity() << ", Price: $" << fruit.get_price() << "\n";
    }
}

