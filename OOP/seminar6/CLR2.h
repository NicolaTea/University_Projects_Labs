//
// Created by Admin on 6/1/2024.
//

#ifndef SEMINAR6_CLR2_H
#define SEMINAR6_CLR2_H

#endif //SEMINAR6_CLR2_H

#include <string>

class Client_InMemory_Repository {
private:
    std::string name;

    static Client_InMemory_Repository *instancePtr;

    // Default constructor declared private
    Client_InMemory_Repository() {}

public:

    // deleting copy constructor
    Client_InMemory_Repository(const Client_InMemory_Repository &obj) = delete;

    /*
      getInstance() is a static method that returns an
      instance when it is invoked. It returns the same
      instance if it is invoked more than once as an instance
      of ClientInMemoryRepository class is already created. It is static
      because we have to invoke this method without any object
      of ClientInMemoryRepository class and static method can be invoked
      without object of class

      As constructor is private so we cannot create object of
      ClientInMemoryRepository class without a static method as they can be
      called without objects. We have to create an instance of
      this ClientInMemoryRepository class by using getInstance() method.
    */
    static Client_InMemory_Repository *getInstance();

    void setValues(const std::string &value);

    void print();
};
