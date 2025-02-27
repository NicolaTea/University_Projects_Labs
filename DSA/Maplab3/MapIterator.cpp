//
// Created by Admin on 4/16/2024.
//

#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;

//theta(1)
MapIterator::MapIterator(const Map& d) : map(d)
{
    //TODO - Implementation
    currentIndex=map.head;
}

//theta(1)
void MapIterator::first() {
    //TODO - Implementation
    currentIndex = map.head;
}

//theta(1)
void MapIterator::next() {
    //TODO - Implementation
    if (!valid()) {
        throw exception();
    }
    currentIndex = map.nodes[currentIndex].next;
}

//theta(1)
bool MapIterator::valid() const {
    //TODO - Implementation
    return currentIndex != -1;
}

//theta(1)
TElem MapIterator::getCurrent() {
    //TODO - Implementation
    if (!valid()) {
        throw exception();
    }
    return map.nodes[currentIndex].info;
}


//theta(1)
void MapIterator::modifyCurrentValue(const TValue& v) {
    if (!valid()) {
        throw exception();
    }
    int current=currentIndex;
    map.nodes[current].info.second=v;


}

//theta(1)
void MapIterator::modifyCurrentKey(const TKey &c)  {
    if (!valid()) {
        throw exception();
    }
    int current=currentIndex;
    map.nodes[current].info.first=c;


}






