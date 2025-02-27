//
// Created by Admin on 4/16/2024.
//

#pragma once
#include "Map.h"
class MapIterator
{
    //DO NOT CHANGE THIS PART
    friend class Map;
private:
    const Map& map;
    //TODO - Representation
    int currentIndex;

    //MapIterator(const Map& m);
public:
    MapIterator(const Map& m);
    void first();
    void next();
    TElem getCurrent();
    bool valid() const;
    void modifyCurrentValue(const TValue& v);
    void modifyCurrentKey(const TKey& c);
};

