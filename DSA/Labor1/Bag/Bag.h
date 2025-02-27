//
// Created by Admin on 4/9/2024.
//

#ifndef BAGLAB1_BAG_H
#define BAGLAB1_BAG_H

#endif //BAGLAB1_BAG_H
#pragma once
//DO NOT INCLUDE BAGITERATOR


//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111;
typedef int TElem;
class BagIterator;
class Bag {

private:
    //TODO - Representation
    int capacity_elem;
    int nrElems;
    int capacity_pos;
    int nrPos;
    TElem *elements;
    int *positions;
    //DO NOT CHANGE THIS PART
    friend class BagIterator;
public:
    //constructor
    Bag();

    //adds an element to the bag
    void add(TElem e);

    //removes one occurence of an element from a bag
    //returns true if an element was removed, false otherwise (if e was not part of the bag)
    bool remove(TElem e);

    //checks if an element appearch is the bag
    bool search(TElem e) const;

    //returns the number of occurrences for an element in the bag
    int nrOccurrences(TElem e) const;

    //returns the number of elements from the bag
    int size() const;

    //returns an iterator for this bag
    BagIterator iterator() const;

    //checks if the bag is empty
    bool isEmpty() const;

    void reverse(Bag& bag)const;

    //destructor
    ~Bag();
};
