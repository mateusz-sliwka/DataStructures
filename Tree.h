//
// Created by Mateusz Śliwka on 2019-04-05.
//

#ifndef SDIZO_SLIWKA_TREE_H
#define SDIZO_SLIWKA_TREE_H

#include "TreeElement.h"
#include <iostream>

using namespace std;

class Tree {
public:
    int size;

    Tree();

    ~Tree();

    void removeAll();

    void add(int);

    void remove(int);

    void rotateLeft(TreeElement *);

    void rotateRight(TreeElement *);

    bool checkIfExists(int);

    void printError(string message);

    void print();

    void printBT(string, string, int);

    void printRBT(string sp, string sn, TreeElement *p);

private:
    TreeElement *root;
    TreeElement sentinel;

    void removeElement(TreeElement *);

    void findElement(int, TreeElement *, TreeElement *&);

    void findValue(int, TreeElement *, bool &found);

    TreeElement *findNextElement(TreeElement *);

    TreeElement *findMinimumElement(TreeElement *);


};


#endif //SDIZO_SLIWKA_TREE_H
