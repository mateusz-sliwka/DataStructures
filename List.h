//
// Created by Mateusz Śliwka on 2019-04-04.
//

#ifndef SDIZO_SLIWKA_LIST_H
#define SDIZO_SLIWKA_LIST_H

#include<iostream>
#include "ListElement.h"

using namespace std;

class List {
public:
    int listSize;

    List();

    ~List();

    ListElement *firstElement;
    ListElement *lastElement;
    ListElement *currentElement;

    void printError(string message);

    void addToTheBeginning(int value);

    void addToTheEnd(int value);

    void addOnPosition(int value, int index);
    void clear();

    void removeLastOne();

    void clean();

    void removeFirstOne();

    void removeElement(int index);

    void printList();

    bool checkIfExist(int value);


};


#endif //SDIZO_SLIWKA_LIST_H
