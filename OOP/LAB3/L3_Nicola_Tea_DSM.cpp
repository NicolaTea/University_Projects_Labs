//
// Created by Admin on 4/8/2024.
//

#include "L3_Nicola_Tea_DSM.h"
#include <string>
#include <vector>
#include <stdexcept>

DSM::DSM(int elementCount):elementCount(elementCount) {
    elementNames.resize(elementCount);
    adjacencyMatrix = new int *[elementCount]; //alocam memorie pt pointer catre int..liniile matricii
    for (int i = 0; i < elementCount; i++)
        adjacencyMatrix[i] = new int[elementCount](); //initializam matricea...coloana
}

DSM::DSM(const std::vector<std::string>& elementNames, int elementCount):  elementCount(elementCount), elementNames(elementNames){
    this->adjacencyMatrix = new int*[elementCount];
    for (int i = 0; i < elementCount; i++) {
        this->adjacencyMatrix[i] = new int[elementCount];
        for (int j = 0; j < elementCount; j++) {
            this->adjacencyMatrix[i][j] = adjacencyMatrix[i][j];
        }
    }
    //this->elementN=new std::string [elementCount];
}


int DSM::size() {
    return elementCount;
}

std::string DSM::getName(int index) {
    if(index<0 || index>=elementCount){
        throw std::out_of_range("Index out of range");
    }
    return elementNames[index];  //return numele elementului la indexul dat
}

void DSM::setElementName(int index, std::string elementName) {
    if(index<0 || index>=elementCount){
        throw std::out_of_range("Index out of range");
    }
    elementNames[index]=elementName; //new index..new name->actualizeaza numele elementului

}

void DSM::addLink(std::string fromElement, std::string toElement, int weight) {
    int fromIndex= getIndex(fromElement);
    int toIndex= getIndex(toElement);
    //std::cout << "fromIndex: " << fromIndex << ", toIndex: " << toIndex << std::endl;
    if (fromIndex==-1 || toIndex==-1){
        throw std::out_of_range("Element not found");
    }
    adjacencyMatrix[fromIndex][toIndex]=weight; //actualizam matricea cu o noua legatura
}

void DSM::deleteLink(std::string fromElement, std::string toElement) {
    int fromIndex= getIndex(fromElement);
    int toIndex= getIndex(toElement);
    if(fromIndex==-1 || toIndex==-1){
        throw std::out_of_range("Element not found");
    }
    adjacencyMatrix[fromIndex][toIndex]=0; //stergem legatura
}

bool DSM::hasLink(std::string fromElement, std::string toElement) {
    int fromIndex=getIndex(fromElement);
    int toIndex=getIndex(toElement);
    if(fromIndex==-1 || toIndex==-1){
        throw std::out_of_range("Element not found");
    }
    return adjacencyMatrix[fromIndex][toIndex]>0; //daca exista o legatura
}

int DSM::linkWeight(std::string fromElement, std::string toElement) {
    int fromIndex=getIndex(fromElement);
    int toIndex=getIndex(toElement);
    if(fromIndex==-1 || toIndex==-1){
        throw std::out_of_range("Element not found");
    }
    return adjacencyMatrix[fromIndex][toIndex]; //care e 'greutatea' legaturii

}

int DSM::countToLinks(std::string elementName) { //cate legaturi sunt catre eleme dat
    int index= getIndex(elementName);
    if (index==-1){
        throw std::out_of_range("Element not found");
    }
    int count=0;
    for (int i=0;i<elementCount;i++){
        if(adjacencyMatrix[i][index]>0){
            count++;
        }
    }
    return count;

}

int DSM::countFromLinks(std::string elementName) { //cate legaturi sunt de la elem dat
    int index= getIndex(elementName);
    if(index==-1){
        throw std::out_of_range("Element not found");
    }
    int count=0;
    for (int i=0;i<elementCount;i++){
        if (adjacencyMatrix[index][i]>0){
            count++;
        }
    }
    return count;
}

int DSM::countAllLinks() {  //toate legaturile din matrice
    int count=0;
    for (int i=0;i<elementCount;i++){
        for(int j=0;j<elementCount;j++){
            //std::cout<<"Element "<<i<<" to "<<j<<": "<<adjacencyMatrix[i][j]<<std::endl;
            if(adjacencyMatrix[i][j]>0){
                count++;
            }
        }
    }
    return count;
}

DSM::~DSM(){
    for (int i=0;i<elementCount;i++){
        delete[] adjacencyMatrix[i];
    }
    delete[] adjacencyMatrix;
}
