//
// Created by Mateusz Śliwka on 2019-04-04.
//

#ifndef SDIZO_SLIWKA_ARRAY_H

#include <iostream>

#define SDIZO_SLIWKA_ARRAY_H
using namespace std;

class Array {
public:
    int *headPtr;
    int arraySize;

    Array();

    ~Array();

    void clean();

    void printError(string message);

    void addToTheBeginning(int value);

    void addToTheEnd(int value);

    void addOnPosition(int value, int index);

    void removeLastOne();

    void removeFirstOne();

    void removeElement(int index);

    void printArray();

    bool checkIfExist(int value);


};


#endif //SDIZO_SLIWKA_ARRAY_H
