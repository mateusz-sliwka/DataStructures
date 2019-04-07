//
// Created by Mateusz Śliwka on 2019-04-04.
//

#ifndef SDIZO_SLIWKA_LISTELEMENT_H
#define SDIZO_SLIWKA_LISTELEMENT_H


class ListElement {
public:
    ListElement *next;
    ListElement *previous;
    int value;

    ListElement(int, ListElement *, ListElement *);

};


#endif //SDIZO_SLIWKA_LISTELEMENT_H
