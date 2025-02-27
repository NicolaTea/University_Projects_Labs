#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;



//theta(1)
Bag::Bag() {
    //TODO - Implementation
    capacity_elem = 10;
    capacity_pos = 20;
    nrPos = 0;
    nrElems = 0;
    positions = new TElem[capacity_pos];
    elements = new TElem[capacity_elem];

}



//B:theta(n)
//AVG:theta(n^2)
//W:theta(n^3)
void Bag::add(TElem elem) {
    //TODO - Implementation
    if (nrElems == capacity_elem)   //dublam capacitatea in vectorul elements
    {
        if (capacity_elem != 0){
            capacity_elem *= 2;
        }
        else{
            capacity_elem = capacity_elem + 1;
        }
        TElem* temp_elem = new TElem[capacity_elem];
        for (int i = 0; i < nrElems; i++)
        {
            temp_elem[i] = elements[i];
        }
        delete elements;
        elements = temp_elem;
    }
    if (nrPos == capacity_pos)  //dublam capacitatea in vectorul positions
    {
        if (capacity_pos != 0){
            capacity_pos *= 2;
        }
        else {
            capacity_pos = capacity_pos + 1;
        }
        capacity_pos *= 2;
        TElem* temp_pos = new TElem[capacity_pos];
        for (int i = 0; i < nrPos; i++)
        {
            temp_pos[i] = positions[i];
        }
        delete positions;
        positions = temp_pos;
    }
    if (search(elem) == false) {	 //daca elem nu este in elements->si positions si elements cresc++
        elements[nrElems] = elem;
        positions[nrPos] = nrElems++;;
        nrPos++;
    }
    else {
        for (int i = 0; i < nrElems; i++) {	//numa positions creste++
            if (elements[i] == elem) {
                positions[nrPos] = i;
                nrPos++;
            }
        }
    }
}


//B:theta(n^3)
//AVG:theta(n^4)->occur==1
//W:theta(n^5)
bool Bag::remove(TElem elem) {
    int idx_el = -1;
    for (int i = 0; i < nrElems; i++) { // cautam elementul in vectorul elements și salvam poziția sa in idx_el
        if (elements[i] == elem) {
            idx_el = i;
            break;
        }
    }

    if (idx_el == -1) {
        return false;
    }

    //numaram aparitiile elementului in vectorul positions
    int occur = 0;
    int last = -1; //ultima poz in care a fost gasita o ref->elem ce urm a fi eliminat din positions
    for (int i = 0; i < nrPos; i++) {
        if (positions[i] == idx_el) {
            occur++;
            last = i;
        }
    }
    if (occur == 1) {

        for (int i = idx_el; i < nrElems - 1; i++) {     //eliminam elementul din elements
            elements[i] = elements[i + 1];
        }
        nrElems--;
        if (idx_el == nrElems) {     //daca elementul eliminat este ultimul din elements, elimina  si din positions
            for (int i = last; i < nrPos - 1; i++) {
                positions[i] = positions[i + 1];
            }
        } else {
            for (int i = last; i < nrPos - 1; i++) {    //altfel eliminam doar referinta din positions si ajustam pozitiile
                positions[i] = positions[i + 1];
            }
            for (int i = 0; i < nrPos; i++) {
                if (positions[i] >= idx_el) {
                    positions[i]--;
                }
            }
        }
        nrPos--;
    } else {
        //daca elementul are mai multe aparitii-> eliminam doar o referinta din positions
        for (int i = last; i < nrPos - 1; i++) {
            positions[i] = positions[i + 1];
        }
        nrPos--;
    }
    return true;
}


//B:theta(1)->primul element
//AVG:theta(n)
//W:theta(n)
bool Bag::search(TElem elem) const {
    //TODO - Implementation
    for (int i = 0; i < nrElems; i++) {
        if (elements[i] == elem){
            return true;
        }
    }
    return false;
}


//B:theta(1)->primul element
//AVG:theta(n)
//W:theta(n^2)
int Bag::nrOccurrences(TElem elem) const {
    //TODO - Implementation
    if (search(elem)) {
        int count = 0;
        for (int i = 0; i < nrPos; i++) {  //cate poz indica catre elem cautat
            if (elements[positions[i]] == elem){
                count = count + 1;
            }
        }
        if (count != 0){
            return count;
        }
    }
    return 0;
}

//theta(1)
int Bag::size() const {
    //TODO - Implementation
    if (nrPos > 0){
        return nrPos;
    }
    return 0;
}

//theta(1)
bool Bag::isEmpty() const {
    //TODO - Implementation
    if (nrPos == 0){
        return true;
    }
    return false;
}

//theta(1)
BagIterator Bag::iterator() const {
    //TODO - Implementation
    return BagIterator(*this);
}

//theta(1)
Bag::~Bag() {
    //TODO - Implementation
    delete[] elements;
    delete[] positions;

}


