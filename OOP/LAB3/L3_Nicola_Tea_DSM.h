//
// Created by Admin on 4/8/2024.
//

#ifndef LAB3_L3_NICOLA_TEA_DSM_H
#define LAB3_L3_NICOLA_TEA_DSM_H
#include<iostream>
#include<vector>

class DSM {
private:
    int elementCount; //nr elemente din sistem
    std::vector<std::string> elementNames; // vector de elemente
    //std::string* elementN;
    int**  adjacencyMatrix;//marice de adiacenta..pointer catre pointer de intregi
public:
    DSM(int elementCount);
    DSM(const std::vector<std::string>& elementNames, int elementCount);
    int size();
    std::string getName(int index);
    void setElementName(int index,std::string elementName);
    void addLink(std::string fromElement, std::string toElement, int
    weight);
    void deleteLink(std::string fromElement, std::string toElement);
    bool hasLink(std::string fromElement, std::string toElement);
    int linkWeight(std::string fromElement, std::string toElement);
    int countToLinks(std::string elementName);
    int countFromLinks(std::string elementName);
    int countAllLinks();
    ~DSM();
    int getIndex(const std::string& elementName){  //functie pt a lua indexul elementului
        for (int i=0;i<elementCount;i++){
            if(elementNames[i]==elementName){
                //std::cout<<"Element found at index "<<i<<std::endl;
                return i;
            }
        }
        //std::cout<<"Element not found"<<std::endl;
        return  -1;
    }

};


#endif //LAB3_L3_NICOLA_TEA_DSM_H
