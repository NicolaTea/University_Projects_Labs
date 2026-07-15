//
// Created by Admin on 6/1/2024.
//

#include "iostream"
#include "CLR2.h"

using namespace std;

Client_InMemory_Repository * Client_InMemory_Repository::instancePtr = nullptr;

Client_InMemory_Repository * Client_InMemory_Repository::getInstance() {
    // If there is no instance of class, then we can create an instance.
    if (instancePtr == nullptr) {
        instancePtr = new  Client_InMemory_Repository();
        return instancePtr;
    } else {
        // If instancePtr != NULL that means the class already has an instance.
        // So, we are returning that instance and not creating new one.
        return instancePtr;
    }
}

void Client_InMemory_Repository::setValues(const string &value) {
    this->name = value;
}

void  Client_InMemory_Repository::print() {
    cout << name << endl;
}