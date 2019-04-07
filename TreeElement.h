//
// Created by Mateusz Śliwka on 2019-04-05.
//

#ifndef SDIZO_SLIWKA_TREEELEMENT_H
#define SDIZO_SLIWKA_TREEELEMENT_H


class TreeElement {
public:
    TreeElement *parent;
    TreeElement *left;
    TreeElement *right;
    char color;
    int value;

};


#endif //SDIZO_SLIWKA_TREEELEMENT_H
