//
// Created by Admin on 4/23/2024.
//
#include<iostream>
#include"Map.cpp"
#include"MapIterator.cpp"
void runTest(){
    Map map;
    map.add(1,10);
    map.add(2,20);
    map.add(3,30);
    map.add(4,40);
    MapIterator it(map);
    for (it.first(); it.valid(); it.next()) {
        std::cout << it.getCurrent().first << ":" << it.getCurrent().second << " ";
    }
    std::cout<<std::endl;
    cout<<"Test modify value "<<endl;
    cout<<"Test modify key "<<endl;
    it.first();
    it.next();
    it.modifyCurrentValue(25);
    it.modifyCurrentKey(5);

    for (it.first(); it.valid(); it.next()) {
        std::cout << it.getCurrent().first << ":" << it.getCurrent().second << " ";
    }
    std::cout<<std::endl;



}
int main(){
    runTest();
    return  0;
}