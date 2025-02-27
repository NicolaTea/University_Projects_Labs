//
// Created by Admin on 5/4/2024.
//

#include "Set.h"
#include "SetIterator.h"
#include<cmath>

//theta(1)
Set::Set() {
    capacity=11;
    length=0;
    nodes= new Node* [capacity]();
}

//B:theta(1)
//AVG:O(n^3)
//W:theta(n^3)
bool Set::add(TElem elem) {
    int idx = calcHash(elem);
    Node* current = nodes[idx];

    while (current != nullptr) { //daca exista deja elementul
        if (current->info == elem) {
            return false;
        }
        current = current->next;
    }

    Node* newNode = new Node(elem); //se adauga la inceput
    newNode->next = nodes[idx];
    nodes[idx] = newNode;

    length++;

    if (length > capacity ) {
        resize();
    }

    return true;
}

//B:theta(1)
//AVG:O(n)
//W:theta(n)
bool Set::remove(TElem elem) {
    int idx = calcHash(elem);
    Node* current = nodes[idx];
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->info == elem) {
            if (prev == nullptr) { //daca este cap
                nodes[idx] = current->next;
            }
            else {
                prev->next = current->next; //se restabilesc legaturile
            }

            delete current;
            length--;
            return true;
        }

        prev = current; //se trece la urm
        current = current->next;
    }

    return false;
}

//B:theta(1)
//AVG:O(n)
//W:theta(n)
bool Set::search(TElem elem) const {
    int idx= calcHash(elem);
    Node* current=nodes[idx];
    while(current != nullptr){
        if(current->info == elem){
            return true;
        }
        current= current->next;
    }
    return false;
}

//theta(1)
int Set::size() const {
    return length;
}

//theta(1)
bool Set::isEmpty() const {
    if(length==0){
        return true;
    }
    return false;
}

//theta(n^2)
Set::~Set() {
    for(int i=0;i<capacity;i++){
        Node* current=nodes[i];
        while(current != nullptr){ //stocam in next si trecem mai departe
            Node* next=current->next;
            delete current;
            current=next;

        }
    }
    delete[] nodes;
}


//theta(1)
SetIterator Set::iterator() const {
    return SetIterator(*this);
}

//theta(1)
int Set::calcHash(TElem elem) const {
    return abs(elem) %capacity;
}

//theta(n^2)
void Set::resize() {
    int new_cap = capacity * 2;
    Node** new_nodes = new Node * [new_cap] {};

    for (int i = 0; i < capacity; i++) {
        Node* current = nodes[i];
        while (current != nullptr) {
            Node* next = current->next;
            int new_idx = abs(current->info % new_cap); //rehash
            current->next = new_nodes[new_idx];
            new_nodes[new_idx] = current;
            current = next;
        }
    }

    capacity = new_cap;
    delete[] nodes;
    nodes = new_nodes;
}

Set Set::intersect(const Set &other) const {
    Set result;
    result.length=0;
    for(int i=0;i<capacity;i++){
        Node* current=nodes[i];
        while(current!= nullptr){
            int idx=abs(current->info)%other.capacity;
            Node* otherCurrent=other.nodes[idx];
            while(otherCurrent!= nullptr){
                if (otherCurrent->info == current->info) {
                    //result.add(current->info);
                    int result_idx=result.calcHash(current->info);
                    Node* newNode=new Node(current->info);
                    newNode->next=result.nodes[result_idx];
                    result.nodes[result_idx]=newNode;
                    result.length++;
                    break;
                }
                otherCurrent=otherCurrent->next;

            }
            current=current->next;
        }
    }
    return result;
}
