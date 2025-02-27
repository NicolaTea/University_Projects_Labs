//
// Created by Admin on 4/9/2024.
//
#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;

//theta(1)
BagIterator::BagIterator(const Bag& c): bag(c)
{
    //TODO - Implementation
    currPos = 0;
}

//theta(1)
void BagIterator::first() {
    //TODO - Implementation
    currPos = 0;
}

//theta(1)
void BagIterator::next() {
    //TODO - Implementation
    if (currPos < bag.nrPos) {
        currPos+= 1;
    }
    else {
       throw exception();
    }
}

//theta(1)
bool BagIterator::valid() const {
    //TODO - Implementation
    if (currPos < bag.nrPos) {
        return true;
    }
    return false;
}


//theta(1)
TElem BagIterator::getCurrent() const
{
    //TODO - Implementation
    if (valid()) {
        return bag.elements[bag.positions[currPos]]; //elem curent din elements la pozitia indicata de currPos
    }
    else {
        throw exception();
    }

}

//TElem BagIterator::modify_Current(TElem e) const {
//    if(valid()){
//        return
//    }else{
//        throw exception();
//    }
//}