//
// Created by Admin on 5/24/2024.
//
#include"Set.h"
void testIntersect(){
    Set s1;
    Set s2;
    s1.add(1);
    s1.add(2);
    s1.add(3);
    s1.add(6);
    s1.add(7);
    s1.add(9);

    s2.add(8);
    s2.add(4);
    s2.add(3);
    s2.add(6);
    s2.add(5);
    s2.add(9);
    Set result=s1.intersect(s2);


}