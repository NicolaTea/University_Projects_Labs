//
// Created by Admin on 4/16/2024.
//

#include "Map.h"
#include "MapIterator.h"



//theta(n)
Map::Map() {
    //TODO - Implementation
    currentSize = 0;
    capacity = 100000;
    nodes = new DLLANode[capacity];
    firstEmpty = 0;
    head = -1;
    tail=-1;
    for (int i = 0; i < capacity; i++) { //legaturi pt DLL
        nodes[i].next = i + 1;
        nodes[i].prev = -1;
    }
    nodes[capacity - 1].next = -1;

}
//B:theta(1)
//Avg:O(n)
//W:theta(n)
TValue Map::add(TKey c, TValue v) {
    //TODO - Implementation
    int newNode = allocateNode();
    TElem elem = std::make_pair(c, v);
    nodes[newNode].info = elem;
    if (isEmpty()) { //lista goala
        head = newNode;
        tail = newNode;
        currentSize++;
        return NULL_TVALUE;
    }
    int current = head;
    while (current != -1) { //trecem pana la sf
        if (nodes[current].info.first == c) {
            TValue value;
            value = nodes[current].info.second;
            nodes[current].info.second = v;
            return value;
        }
        current = nodes[current].next;
    }
    nodes[newNode].prev = tail;  //adaug la sf
    nodes[tail].next = newNode;
    tail = newNode;
    currentSize++;
    return NULL_TVALUE;


}

//B:theta(1)
//Avg:theta(n)
//W:theta(n)
TValue Map::search(TKey c) const {
    //TODO - Implementation
    if (isEmpty())
        return NULL_TVALUE;
    int current = head;
    while (current != -1) {
        if (nodes[current].info.first == c) {
            return nodes[current].info.second;
        }
        current = nodes[current].next;
    }
    return NULL_TVALUE;
}


//B:theta(1)
//Avg:O(n)
//W:theta(n)
TValue Map::remove(TKey c) {
    //TODO - Implementation
    if (isEmpty() || search(c) == NULL_TVALUE)
        return NULL_TVALUE;
    int current = head;
    while (current != -1 && nodes[current].info.first != c) {
        current = nodes[current].next;
    }
    int prevNode = nodes[current].prev;
    int nextNode = nodes[current].next;
    //actualizare daca nodul->cap sau coada
    if (prevNode == -1) { //daca este cap
        if (nextNode == -1) {
            head = -1;
            tail = -1;
        } else {
            head = nextNode;
            nodes[head].prev = -1;
        }
    } else if (nextNode == -1) { //daca este coada
        tail = prevNode;
        nodes[tail].next = -1;
    } else {                        //este intre cap si coada
        nodes[prevNode].next = nextNode;
        nodes[nextNode].prev = prevNode;
    }
    TValue value;   //nodul eliminat ->lista nod libere
    value = nodes[current].info.second;
    nodes[current].next = firstEmpty;
    firstEmpty = current;
    nodes[firstEmpty].prev = -1;
    currentSize--;
    return value;
}

//theta(1)
int Map::size() const {
    //TODO - Implementation
    return currentSize;
}

//theta(1)
bool Map::isEmpty() const {
    //TODO - Implementation
    if (currentSize == 0)
        return true;
    return false;
}

//theta(1)
MapIterator Map::iterator() const {
    return MapIterator(*this);
}

//theta(1)
Map::~Map() {
    //TODO - Implementation
    delete[] nodes;
}

//theta(1)
int Map::allocateNode() { //fct aux pt alocare nod pt a fi utilizat
    int pos = firstEmpty;
    if (pos != -1) {
        firstEmpty = nodes[firstEmpty].next;
        if (firstEmpty != -1) {
            nodes[firstEmpty].prev = -1;
        }
        nodes[pos].next = -1;
        nodes[pos].prev = -1;
    }
    return pos;
}