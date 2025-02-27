#ifndef LAB2_L2_NICOLA_TEA_PROBLEM0_H
#define LAB2_L2_NICOLA_TEA_PROBLEM0_H

#endif //LAB2_L2_NICOLA_TEA_PROBLEM0_H
#include<string>
#include<iostream>
using namespace std;


class Length {
private:
    double value;
    string unit;

public:
    Length(double val, string u);
    double get_value();
    string get_unit();
    Length add(Length other);
    Length subtract(Length other);
    Length scale(double factor);
    Length divide(double divisor);
    string text();
    int compare(Length other);
    void readFromInput() {
        cin >> value >> unit;
    }
};