//
// Created by Mateusz Śliwka on 2019-04-04.
//

#include "List.h"
#include <iostream>

using namespace std;

void List::printError(string message) {
    cout << "[ERROR] " + message << endl;
}

List::List() {
    List::firstElement = NULL;
    List::currentElement = NULL;
    List::lastElement = NULL;
    List::listSize = 0;
}

List::~List() {
    for (int i = 0; i < List::listSize; i++) {
        //Przypisanie nastepnego elementu jako aktualny
        currentElement = firstElement->next;
        //Usunięcie pierwszego elementu
        delete firstElement;
        firstElement = currentElement;
    }
}

void List::addToTheBeginning(int value) {
    //Sprawdzam czy lista jest niepusta
    if (firstElement != NULL) {
        //Ustawienie pierwszego elementu jako aktualnego
        currentElement = firstElement;
        //Wpisanie do pierwszego elementu nowego elementu
        firstElement = new ListElement(value, currentElement, NULL);
        //Ustawienie pierwszego el. jako poprzedni aktualnego
        currentElement->previous = firstElement;
    } else {
        //Dodanie nowego elementu jako jedyny istniejący w liścier
        firstElement = new ListElement(value, NULL, NULL);
        lastElement = firstElement;
    }
    //Zwiększenie rozmiaru listy z racji dodanego elementu
    listSize += 1;
}

void List::addToTheEnd(int value) {
    if (firstElement != NULL) {
        //Ustawienie ostatniego elementu jako aktualnego
        currentElement = lastElement;
        //Wpisanie do ostatniego elementu nowego elementu
        lastElement = new ListElement(value, NULL, currentElement);
        //Ustawienie ostatniego el. jako nastepny aktualnego
        currentElement->next = lastElement;
    } else {
        //Dodanie nowego elementu jako jedyny istniejący w liścier
        lastElement = new ListElement(value, NULL, NULL);
        firstElement = lastElement;
    }
    //Zwiększenie rozmiaru listy z racji dodanego elementu
    listSize += 1;
}

void List::addOnPosition(int value, int index) {
    //Sprawdzenie czy pozycja istnieje lub czy jest ostatnia lub pierwsza
    if (index == 0)
        List::addToTheBeginning(value);
    else if (index == listSize - 1)
        List::addToTheEnd(value);
    else if (index < 0 || index > listSize)
        List::printError("W liście nie ma takiej pozycji.");
    else {
        //Sprawdzamy w ktorej polowie listy jest pozycja
        if (value < listSize / 2) {
            currentElement = firstElement;
            //Przesuwanie elementow o jeden dalej
            for (int i = 1; i < index - 1; i++)
                currentElement = currentElement->next;
        } else {
            currentElement = lastElement;
            //Przesuwanie elementów o jeden wstecz
            for (int i = 0; i < List::listSize - index - 1; i++)
                currentElement = currentElement->previous;
        }
        ListElement *newListElement = new ListElement(value, currentElement, currentElement->next);
        currentElement->next->previous = newListElement;
        currentElement->next = newListElement;
        listSize += 1;
    }
}

void List::removeFirstOne() {
    //Przypisz drugi element jako aktualny
    currentElement = firstElement->next;
    //Usun pierwszy element
    delete firstElement;
    //Sprawdzamy czy sa inne elementy jak tak to ustawiami aktualny jako pierwszy jesli nie to zerujemy
    if (listSize > 1) {
        currentElement->previous = NULL;
        firstElement = currentElement;
    } else {
        currentElement = NULL;
        firstElement = NULL;
        lastElement = NULL;
    }
    listSize--;
}

void List::removeLastOne() {
    if (listSize == 1)
        removeFirstOne();
    else {
        //Przypisz drugi element jako aktualny
        currentElement = lastElement->previous;
        //Usun pierwszy element
        delete lastElement;
        //Sprawdzamy czy sa inne elementy jak tak to ustawiami aktualny jako pierwszy jesli nie to zerujemy
        if (listSize > 1) {
            currentElement->next = NULL;
            lastElement = currentElement;
        } else {
            currentElement = NULL;
            firstElement = NULL;
            lastElement = NULL;
        }
        listSize--;
    }

}

void List::removeElement(int index) {
    if (index == 0)
        List::removeFirstOne();
    else if (index == listSize - 1)
        List::removeLastOne();
    else if (index < 0 || index > listSize)
        List::printError("W liście nie ma takiej pozycji.");
    else {
        currentElement = firstElement;
        for (int i = 1; i < index - i; i++) {
            cout << currentElement;
            currentElement = currentElement->next;
        }
        ListElement *newListElement = currentElement->next;
        currentElement->next = newListElement->next;
        currentElement->next->previous = newListElement;
        delete[]newListElement;
        listSize--;
    }
}

bool List::checkIfExist(int value) {
    //Sprawdzenie czy lista nie jest pusta
    if (listSize == 0) {
        List::printError("Lista jest pusta.");
        return false;
    }
    currentElement = firstElement;
    //Przeiterowanie po elementach listy i przyrownanie wartosci do szukanej
    for (int i = 0; i < listSize; i++) {
        if (currentElement->value == value) {
            cout << "Wartośc znaleziona na pozycji " << i << endl;
            return true;
        }
        currentElement = currentElement->next;
    }
    //Jesli funckja dalej chodzi tzn ze nie bylo wczesniejszego returna i nie znaleziono elementu
    cout << "Nie znaleziono wartosci w liscie." << endl;
    return false;
}

void List::printList() {
    if (listSize == 0) {
        List::printError("Lista jest pusta.");
    }
    currentElement = firstElement;
    for (int i = 0; i < listSize; i++) {
        cout << "[" << i << "]" << currentElement->value << endl;
        //Przypisanie obecnemy elementowi kolejny
        currentElement = currentElement->next;
    }
}
