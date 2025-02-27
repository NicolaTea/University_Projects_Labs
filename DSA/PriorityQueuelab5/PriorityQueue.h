//
// Created by Admin on 5/24/2024.
//

#pragma once
#include <vector>
#include <utility>

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TElem;
typedef int TPriority;
typedef std::pair<TElem, TPriority> Element;
typedef bool (*Relation)(TPriority p1, TPriority p2);
#define NULL_TELEM pair<TElem, TPriority> (-11111,-11111);

class PriorityQueue {
private:
    //TODO - Representation
    Element * info;
    int* left;
    int* right;
    int root;
    int firstEmpty;
    int cap;
    Relation rel;

public:
    //implicit constructor
    PriorityQueue(Relation r);

    //pushes an element with priority to the queue
    void push(TElem e, TPriority p);

    //returns the element with the highest priority with respect to the order relation
    //throws exception if the queue is empty
    Element top()  const;

    //removes and returns the element with the highest priority
    //throws exception if the queue is empty
    Element pop();

    //checks if the queue is empty
    bool isEmpty() const;

    //destructor
    ~PriorityQueue();

    void resize();

    bool operator==(const PriorityQueue& other) const;

    bool are_equal(int n1,int n2,const PriorityQueue& other)const;

};