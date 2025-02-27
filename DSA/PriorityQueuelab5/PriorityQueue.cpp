//
// Created by Admin on 5/24/2024.
//

#include "PriorityQueue.h"
#include <exception>
using namespace std;

//theta(n)
PriorityQueue::PriorityQueue(Relation r) {
    cap=11;
    info= new Element[cap];
    left= new int[cap];
    right= new int[cap];
    root=-1;
    firstEmpty=0;
    rel=r;
    for(int i=0;i<cap-1;i++){ //init spatii libere..fiecare elem indica urm elem liber
        left[i]=i+1;
    }
    left[cap-1]=-1;
}

//theta(n)
void PriorityQueue::resize() {
    int new_cap = cap * 2;

    Element* new_info = new Element[new_cap];
    int* new_left = new int[new_cap];
    int* new_right = new int[new_cap];

    for (int i = 0; i < cap; i++) {
        new_info[i] = info[i];
        new_left[i] = left[i];
        new_right[i] = right[i];
    }

    for (int i = cap; i < new_cap - 1; i++) {
        new_left[i] = i + 1;
    }
    new_left[new_cap - 1] = -1;

    delete[] info;
    delete[] left;
    delete[] right;

    info = new_info;
    left = new_left;
    right = new_right;
    firstEmpty = cap;
    cap = new_cap;
}

//B:theta(1)
//AVG:theta(n)
//W:theta(n)
void PriorityQueue::push(TElem e, TPriority p) {
    if (firstEmpty == -1) { //nu avem indici liberi
        resize();
    }

    int newNode = firstEmpty;
    firstEmpty = left[firstEmpty];
    info[newNode] = std::make_pair(e, p);
    left[newNode] = -1;
    right[newNode] = -1;

    if (root == -1) {  //devine radacina
        root = newNode;
    } else {
        int currNode = root;
        int parent = -1;

        while (currNode != -1) {
            parent = currNode;
            if (rel(p, info[currNode].second)) { //prioritatea: e>currNode
                currNode = left[currNode];
            } else {
                currNode = right[currNode]; //prioritatea: e<currNode
            }
        }
        if (rel(p, info[parent].second)) {  //pe baza relatiei se adauga noul nod
            left[parent] = newNode;
        } else {
            right[parent] = newNode;
        }
    }
}


//theta(n)
Element PriorityQueue::top() const {
    if(isEmpty()){
        throw exception();
    }
    int currNode=root;
    while(left[currNode] != -1){  //merge la stanga pana gaseste elem cel mai mic
        currNode=left[currNode];
    }
    return info[currNode];
}


//B:theta(1)
//AVG:theta(n)
//W:theta(n)
Element PriorityQueue::pop() {
    if (isEmpty()) {
        throw exception();
    }

    int currNode = root;
    int parent = -1;


    while (left[currNode] != -1) {  //gasim nodul cu cea mai mare prioritate (cea mai mica valoare)
        parent = currNode;
        currNode = left[currNode];
    }

    Element topElement = info[currNode];

    if (left[currNode] == -1 && right[currNode] == -1) {  //nodul este frunza
        if (parent == -1) {
            root = -1;
        } else {
            left[parent] = -1;
        }
    } else if (left[currNode] == -1) {  //nodul are doar subarbore drept
        if (parent == -1) {
            root = right[currNode];
        } else {
            left[parent] = right[currNode];
        }
    } else if (right[currNode] == -1) {  //nodul are doar subarbore stang
        if (parent == -1) {
            root = left[currNode];
        } else {
            left[parent] = left[currNode];
        }
    } else {  //nodul are ambii subarbori
        int succParent = currNode;
        int succ = right[currNode];

        while (left[succ] != -1) {
            succParent = succ;
            succ = left[succ];
        }

        info[currNode] = info[succ];

        if (succParent != currNode) {
            left[succParent] = right[succ];
        } else {
            right[succParent] = right[succ];
        }
    }

    left[currNode] = firstEmpty;
    firstEmpty = currNode;

    return topElement;
}

//theta(1)
bool PriorityQueue::isEmpty() const {
    if(root==-1){
        return true;
    }
    return false;
}

//theta(1)
PriorityQueue::~PriorityQueue() {
    delete [] info;
    delete [] left;
    delete [] right;
};


bool PriorityQueue::are_equal(int n1, int n2, const PriorityQueue &other) const {
    if(n1==-1 && n2==-1){
        return true;
    }
    if(n1==-1 || n2==-1){
        return false;
    }
    if(info[n1] !=other.info[n2]){
        return false;
    }
    return are_equal(left[n1], other.left[n2], other) &&
           are_equal(right[n1], other.right[n2], other);
}

bool PriorityQueue::operator==(const PriorityQueue &other) const {
    if(root==-1 && other.root==-1){
        return true;
    }
    if(root==-1 || other.root==-1){
        return false;
    }
    return are_equal(root,other.root,other);

}