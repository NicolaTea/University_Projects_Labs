//
// Created by Admin on 4/9/2024.
//

#ifndef MULTIMAPLAB2_MULTIMAPITERATOR_H
#define MULTIMAPLAB2_MULTIMAPITERATOR_H

#endif //MULTIMAPLAB2_MULTIMAPITERATOR_H
#pragma once
#include "MultiMap.h"

class MultiMap;

class MultiMapIterator
{
    friend class MultiMap;

private:
    const MultiMap& col;
    //TODO - Representation
    KeyNode* currentKey;
    ValueNode* currentValue;
    void next_key();
    MultiMapIterator(const MultiMap& c);
public:
    TElem getCurrent()const;
    bool valid() const;
    void next();
    void first();
};

