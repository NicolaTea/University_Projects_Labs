//
// Created by Admin on 4/9/2024.
//
#include "MultiMapIterator.h"
#include "MultiMap.h"

//theta(1)
MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
    //TODO - Implementation
    currentKey = c.head; //inceputul listei de chei si val
    if (currentKey != nullptr) {
        currentValue = currentKey->valueHead; //inceputul listei asociate cu prima cheie
    }
    else {
        currentValue = nullptr;
    }
}

//theta(1)
TElem MultiMapIterator::getCurrent() const {
    //TODO - Implementation
    if (currentValue == nullptr) {
        throw exception();
    }
    TElem result = make_pair(currentKey->key, currentValue->value);
    return result;
}

//theta(1)
bool MultiMapIterator::valid() const {
    //TODO - Implementation
    if(currentKey!= nullptr){
        return true;
    }
    return false;
}

//theta(1)
void MultiMapIterator::next() {
    //TODO - Implementation
    if (currentKey == nullptr) { //am ajuns la sf cointainer
        throw exception();
    }
    currentValue = currentValue->next; //urm elem
    if (currentValue == nullptr) { //am terminat de parcus pt cheia curenta
        next_key();
    }

}

//theta(1)
void MultiMapIterator::first() {
    //TODO - Implementation
    currentKey = col.head;
    currentValue = currentKey->valueHead;
}

//theta(1)
void MultiMapIterator::next_key() { //metoda aux pt a muta iteratorul la urm nod cheie
    currentKey = currentKey->nextKey;
    if (currentKey != nullptr) {
        currentValue = currentKey->valueHead;
    }
}

