//
// Created by Admin on 4/9/2024.
//

#include "Fruit.h"
#include <string>
using std::string;

Fruit::Fruit(string name, string origin,string expiration_date, int price, int quantity): name(name), origin(origin), expiration_date(expiration_date), quantity(quantity), price(price) {}

Fruit::~Fruit() = default;

string Fruit::get_name() const {
    return name;
}

string Fruit::get_origin() const {
    return origin;
}

int Fruit::get_price() const{
    return price;
}

void Fruit::set_price(int new_p) {
   price = new_p;
}

void Fruit::set_quantity(int new_q) {
    quantity=new_q;
}

int Fruit::get_quantity() const {
    return quantity;
}

string Fruit::get_expiration_date() const {
    return expiration_date;
}

bool Fruit::operator==(Fruit &other) {
    if(name == other.name and origin == other.origin) {
        return true;
    }
    return false;
}



Fruit Fruit::operator+(Fruit &other) {
    if(*this == other) {
        quantity += other.quantity;
    }
    return *this;
}
