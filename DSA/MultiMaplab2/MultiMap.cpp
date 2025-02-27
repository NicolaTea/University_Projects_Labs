//
// Created by Admin on 4/9/2024.
//
#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;

//theta(1)
MultiMap::MultiMap() {
    //TODO - Implementation
    head = nullptr;
    nrElem = 0;
}


//theta(1)
void MultiMap::add(TKey c, TValue v) {
    //TODO - Implementation
    KeyNode* the_key = get_key(c);
    ValueNode* newNode = new ValueNode[1]; //creeam un nod nou pt valori
    newNode->value = v;
    newNode->next = nullptr;
    nrElem++;
    if(the_key != nullptr) { //daca key exista +atasam la inceput liseti de val asociate key
        newNode->next = the_key->valueHead;
        the_key->valueHead = newNode;

    } else {  //key nu exista->creeam un nou nod->adaugam valorile
        KeyNode* new_key = new KeyNode[1];
        new_key->key = c;
        new_key->nextKey = this->head;
        this->head = new_key;
        new_key->valueHead = newNode;
    }
}


//B:theta(n)
//AVG:theta(n)
//W:theta(n^2)
bool MultiMap::remove(TKey c, TValue v) {
    //TODO - Implementation
    KeyNode* the_key =get_key(c);
    if(the_key == nullptr) {
        return false;
    }
    ValueNode* current = the_key->valueHead;
    ValueNode* previous = nullptr;
    while (current != nullptr && current->value != v) { //cautam elementul pt remove..parcurgem lista de valori asociate unui key
        previous = current;
        current = current->next;
    }
    if(current != nullptr && previous == nullptr) { //daca elementul este primu+ actualizam capul listei de valori
        the_key->valueHead = the_key->valueHead->next;
        delete current;
        nrElem--;
        if(the_key->valueHead == nullptr)  //daca lista de valori a key este empty
            remove_key(c);
        return true;

    } else if (current != nullptr) {   //daca elementul nu este primu+schimbam legaturile ca dupa sa stergem nodu
        previous->next = current->next;
        current->next = nullptr;
        delete current;
        nrElem--;
        return true;
    }
    delete current;
    return false;
}


//B:theta(1)
//AVG:theta(n),where n=nr_keys
//W:theta(n),where n=nr_keys
vector<TValue> MultiMap::search(TKey c) const {
    //TODO - Implementation
    vector<TValue> result{};
    KeyNode* the_key = get_key(c);
    if(the_key == nullptr)
        return result;
    ValueNode* current = the_key->valueHead; //un ->nodul curent
    while (current != nullptr) { //parcurgem lista de valori asociate key+ adaugam in result
        result.push_back(current->value);
        current = current->next;
    }
    return result;
}

//theta(1)
int MultiMap::size() const {
    //TODO - Implementation
    return nrElem;
}

//theta(1)
bool MultiMap::isEmpty() const {
    //TODO - Implementation
    if(head== nullptr){
        return true;
    }
    return false;

}

//theta(1)
MultiMapIterator MultiMap::iterator() const {
    return MultiMapIterator(*this);
}

//theta(n^2)
MultiMap::~MultiMap() {
    //TODO - Implementation
    KeyNode* currentKey = head; //un -> capu listei
    while (currentKey != nullptr) {
        ValueNode* currentValueNode = currentKey->valueHead; //stergem toate ValueNodes asociate cu KeyNode curent
        while (currentValueNode != nullptr) {
            ValueNode* nextValueNode = currentValueNode->next;
            delete currentValueNode;
            currentValueNode = nextValueNode; //trecem la urmatoarea valoare
        }
        KeyNode* nextKeyNode = currentKey->nextKey;  //stergem KeyNode curent
        delete currentKey;
        currentKey = nextKeyNode; //trecem la urmatorul key
    }
    head = nullptr;
    nrElem = 0;
}


//theta(n),where n=nr_keys
KeyNode * MultiMap::get_key(TKey key) const { //o referinta la KeyNode-ul asociat unei key
    KeyNode* current = this->head;
    while(current != nullptr) { //cautam key
        if(current->key == key) {
            return current;
        }
        current = current->nextKey; //urm key
    }
    return nullptr;
}


//theta(n), where n=nr keys
void MultiMap::remove_key(TKey key) { //stergam key specificat
    KeyNode* current = this->head;
    KeyNode* previous = nullptr;
    while(current != nullptr && current->key != key) {  //cautam key + trecem la urm key
        previous = current;
        current = current->nextKey;
    }
    if(current != nullptr && previous == nullptr) {  //key e primu
        this->head = this->head->nextKey;
        delete current;
    } else if(current != nullptr) {   //key nu e primu
        previous->nextKey = current->nextKey;
        current->nextKey = nullptr;
        delete current;
    }
}

void MultiMap::reverse(MultiMap &multimap) {
    if(multimap.isEmpty()||multimap.size()==1){
        return;
    }
    KeyNode* current=multimap.head;
    KeyNode* previous= nullptr;
    KeyNode* next= nullptr;
    while(current!= nullptr){
        next=current->nextKey;
        current->nextKey=previous;
        previous=current;
        current=next;

    }
    multimap.head=previous;

}

