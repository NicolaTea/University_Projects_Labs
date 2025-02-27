//
// Created by Admin on 4/8/2024.
//
#include <iostream>
#include <vector>
#include <stdexcept>
#include "L3_Nicola_Tea_DSM.cpp"
using namespace std;

int main() {

    std::vector<std::string> litere={"U","X"};
    DSM dsm(13);
    DSM dsm2(litere,2);


    //Size
    cout<<"Size of Dsm: "<<dsm.size()<<endl;

    // setElementName
    dsm.setElementName(0, "A");
    dsm.setElementName(1, "B");
    dsm.setElementName(2, "C");
    dsm.setElementName(3, "D");
    dsm.setElementName(4, "E");
    dsm.setElementName(5, "F");
    dsm.setElementName(6, "G");
    dsm.setElementName(7, "H");
    dsm.setElementName(8, "I");
    dsm.setElementName(9, "J");
    dsm.setElementName(10, "K");
    dsm.setElementName(11, "L");
    dsm.setElementName(12, "M");

    //getName
    cout<<"Name from index: "<<dsm.getName(5)<<endl;
    cout<<"Name from index: "<<dsm.getName(2)<<endl;
    cout<<"Name from index: "<<dsm.getName(4)<<endl;

    // AddLink
    dsm.addLink("A", "C", 5);
    dsm.addLink("B", "D", 1);
    dsm.addLink("D", "G", 3);
    dsm.addLink("G", "I", 8);
    dsm.addLink("I", "K", 2);
    dsm.addLink("C", "E", 4);
    dsm.addLink("C", "F", 1);
    dsm.addLink("F", "K", 1);
    dsm.addLink("H", "J", 1);
    dsm.addLink("J", "L", 1);
    dsm.addLink("L", "M", 6);
    dsm.addLink("K", "M", 7);

    // Testam Analysemethoden
    cout << "A has link to B: " << dsm.hasLink("A", "B") << endl;
    cout << "A has link to C: " << dsm.hasLink("A", "C") << endl;
    cout << "Link weight from G to I: " << dsm.linkWeight("G", "I") << endl;
    cout << "Count of links to M: " << dsm.countToLinks("M") << endl;
    cout << "Count of links from C: " << dsm.countFromLinks("C") << endl;
    cout << "Count of all links: " << dsm.countAllLinks() << endl;

    // deletelink
    dsm.deleteLink("B", "D");
    cout << "B has link to D after deletion: " << dsm.hasLink("B", "D") << endl;

    return 0;
}