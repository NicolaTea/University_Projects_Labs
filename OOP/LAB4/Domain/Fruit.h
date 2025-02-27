//
// Created by Admin on 4/9/2024.
//

#ifndef LAB4_FRUIT_H
#define LAB4_FRUIT_H
#include<iostream>

class Fruit {
private:
    std::string name;
    std::string origin;
    std::string expiration_date;
    int quantity;
    int price;

public:
    //Constructor
    Fruit(std::string name, std::string origin, std::string expiration_date, int price, int quantity);

    //Destructor
    ~Fruit();

    //Operator
    bool operator==(Fruit& other);
    Fruit operator+(Fruit& other);


    // Getter methods
    std::string get_name() const;
    std::string get_origin() const;
    std::string get_expiration_date() const;
    int get_quantity() const;
    int get_price() const;

    // Setter methods
    void set_price(int new_p);
    void set_quantity(int new_q);



};


#endif //LAB4_FRUIT_H
