//
// Created by Mateusz Śliwka on 2019-04-04.
//

#include "ListElement.h"


ListElement::ListElement(int value, ListElement *next, ListElement *previous) {
    ListElement::value = value;
    ListElement::next = next;
    ListElement::previous = previous;
}