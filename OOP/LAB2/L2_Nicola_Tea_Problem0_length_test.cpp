//
// Created by Admin on 4/8/2024.
//
#include"L2_Nicola_Tea_Problem0_length.cpp"
#include<iostream>
#include "assert.h"
using namespace std;

int main(){
    Length len1(0,"");
    Length len2(0,"");
//    Length l1(5,"km");
//    Length l2(2,"km");
    double factor, divisor ;
    cout << "Give me a value and a unit for len1: ";
    len1.readFromInput();
    cout << "Give me a value and a unit for len2: ";
    len2.readFromInput();
    cout << "Give me a factor: ";
    cin >> factor;
    cout << "Give me a divisor: ";
    cin >> divisor;
    cout<<"Addition: "<<len1.add(len2).text()<<std::endl;
    cout<<"Subtraction: "<<len1.subtract(len2).text()<<std::endl;
    cout<<"Scaling_len1: "<<len1.scale(factor).text()<<std::endl;
    cout<<"Division_len1: "<<len1.divide(divisor).text()<<std::endl;
    cout<<"Scaling_len2: "<<len2.scale(factor).text()<<std::endl;
    cout<<"Division_len2: "<<len2.divide(divisor).text()<<std::endl;
    cout << "Comparison result: " << len1.compare(len2) << std::endl;

//    assert((l1.add(l2)).text() == "Length: 7");
//    assert((l1.subtract(l2)).text() == "Length: 3");
//    assert((l1.scale(2)).text() == "Length: 10");
//    assert((l1.divide(5)).text() == "Length: 1");
//    assert(l1.compare(l2) == 1);

    return 0;


}