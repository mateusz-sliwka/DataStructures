//
// Created by Mateusz Śliwka on 2019-04-05.
//

#ifndef SDIZO_SLIWKA_HEAP_H
#define SDIZO_SLIWKA_HEAP_H

#include <iostream>

using namespace std;


class Heap {
public:
    int *array;
    unsigned int size;

    Heap();

    ~Heap();

    void add(int);

    void remove(int);

    bool checkIfExist(int);

    void printHeap();


    void rebuildHeap();

    int countLevel();

    void printBT(string, string, int);
};


#endif //SDIZO_SLIWKA_HEAP_H
