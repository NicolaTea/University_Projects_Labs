//
// Created by Admin on 4/9/2024.
//

#ifndef BAGLAB1_BAGITERATOR_H
#define BAGLAB1_BAGITERATOR_H

#endif //BAGLAB1_BAGITERATOR_H
#include "Bag.h"

class BagIterator
{
    //DO NOT CHANGE THIS PART
    friend class Bag;

private:
    const Bag& bag;
    //TODO  - Representation
    int currPos;

    BagIterator(const Bag& c);
public:
    void first();
    void next();
    TElem getCurrent() const;
    bool valid() const;
    TElem modify_Current(TElem e)const;
};
