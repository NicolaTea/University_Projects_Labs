//
// Created by Admin on 5/4/2024.
//

#include "SetIterator.h"
#include "Set.h"
#include <exception>
using namespace std;

//theta(n)
SetIterator::SetIterator(const Set& m) : set(m)
{
    currentPos=0;
    current= nullptr;
    while(currentPos<set.capacity && set.nodes[currentPos]== nullptr){
        currentPos++;
    }
    if(currentPos<set.capacity){
        current=set.nodes[currentPos];
    }


}

//theta(n)
void SetIterator::first() {
    currentPos=0;
    current= nullptr;
    while(currentPos<set.capacity && set.nodes[currentPos]== nullptr){ //parcurgem hashtable pana gasim spatiu
        currentPos++;
    }
    if(currentPos<set.capacity){
        current=set.nodes[currentPos]; //primul nod din spatiu
    }

}

//theta(n)
void SetIterator::next() {
    if(!valid()){
        throw exception();
    }
    current=current->next;
    while(currentPos<set.capacity && current== nullptr){
        currentPos++;
        if(currentPos<set.capacity){
            current=set.nodes[currentPos];
        }
    }

}

//theta(1)
TElem SetIterator::getCurrent()
{
    if (!valid()){
        throw exception();
    }
    return current->info;

}

//theta(1)
bool SetIterator::valid() const {
    if(currentPos<set.capacity && current != nullptr){
        return true;
    }
    return false;
}




