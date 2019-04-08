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
        //Przypisanie nastepnego elementu jako current
        currentElement = firstElement->next;
        //Usunięcie pierwszego elementu
        delete firstElement;
        firstElement = currentElement;
    }
}

void List::clear() {
    List::firstElement = NULL;
    List::currentElement = NULL;
    List::lastElement = NULL;
    List::listSize = 0;
}

void List::addToTheBeginning(int value) {
    //Sprawdzam czy lista jest niepusta
    if (firstElement != NULL) {
        //Ustawienie pierwszego elementu jako aktualnego
        currentElement = firstElement;
        //Wpisanie do pierwszego elementu nowego elementu
        firstElement = new ListElement(value, currentElement, NULL);
        //Ustawienie pierwszego el. jako previous aktualnego
        currentElement->previous = firstElement;
    } else {
        //Dodanie nowego elementu jako jedyny istniejący w liścier
        firstElement = new ListElement(value, NULL, NULL);
        lastElement = firstElement;
    }
    //Zwiększenie listSizeu listy z racji dodanego elementu
    listSize++;
}

void List::addToTheEnd(int value) {
    if (firstElement != NULL) {
        //Ustawienie ostatniego elementu jako aktualnego
        currentElement = lastElement;
        //Wpisanie do ostatniego elementu nowego elementu
        lastElement = new ListElement(value, NULL, currentElement);
        //Ustawienie ostatniego el. jako next aktualnego
        currentElement->next = lastElement;
    } else {
        //Dodanie nowego elementu jako jedyny istniejący w liścier
        lastElement = new ListElement(value, NULL, NULL);
        firstElement = lastElement;
    }
    //Zwiększenie listSizeu listy z racji dodanego elementu
    listSize++;
}

void List::addOnPosition(int value, int index) {
    if(index==listSize){
        List::addToTheEnd(value);
    }
    //Sprawdź czy w liście istnieje index podana przez użytkownika
    if (index < 0 || index > listSize) {
        cout << "W liście nie istnieje index [" << index << "]" << endl;
        return;
    }
    //Sprawdź czy wybrana index jest pierwszą
    if (index == 0) {
        List::addToTheBeginning(value);
        return;
    }

    //Sprawdź czy wybrana index jest ostatnią
    if (index == listSize - 1) {
        addToTheEnd(value);
        return;
    }

    //Sprawdź w której połowie listy znajduje się wybrany element
    if (index < listSize / 2) { //liczone od indeksu zerowego
cout<<"tu"<<endl;
        //Przypisz za current element first
        currentElement = firstElement;

        //Przesuń wszyskie elementy o jeden dalej
        for (int i = 0; i < index - 1; ++i) {

            currentElement = currentElement->next;
        }

    } else {

        //Przypisz za current element ostatni
        currentElement = lastElement->previous;

        //Przesuń wszystkie elementy o jedną pozycję wstecz
        for (int i = 0; i < List::listSize - index - 1; ++i) {
            currentElement = currentElement->previous;
        }

    }

    //Stwórz new element listy z podanymi parametrami
    ListElement *newlistElement = new ListElement(value, currentElement->next,
                                                  currentElement);

    //przypisz new element w odpowiednim miejscu tablicy
    currentElement->next->previous = newlistElement;
    currentElement->next = newlistElement;

    //Zwiększ listSize listy
    listSize = listSize + 1;

}

void List::removeFirstOne() {
    //Przypisz drugi element jako current
    currentElement = firstElement->next;
    //Usun first element
    delete firstElement;
    //Sprawdzamy czy sa inne elementy jak tak to ustawiami current jako first jesli nie to zerujemy
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
        //Przypisz drugi element jako current
        currentElement = lastElement->previous;
        //Usun first element
        delete lastElement;
        //Sprawdzamy czy sa inne elementy jak tak to ustawiami current jako first jesli nie to zerujemy
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


    if (index < 0 || index > listSize) {
        cout << "W liście nie istnieje   index [" << index << "]" << endl;
        return;
    }
    //Sprawdź czy wybrana   index jest pierwszą
    if (index == 0) {
        removeFirstOne();
        return;
    }

    //Sprawdź czy wybrana   index jest ostatnią
    if (index == listSize - 1) {
        removeLastOne();
        return;
    }

    //Sprawdź w której połowie listy znajduje się wybrany element
    if (index < listSize / 2) {

        //Przypisz za current element first
        currentElement = firstElement;

        //Przesuń wszyskie elementy o jeden dalej
        for (int i = 1; i < index - 1; ++i) {
            currentElement = currentElement->next;
        }

    } else {

        //Przypisz za current element ostatni
        currentElement = lastElement->previous;

        //Przesuń wszystkie elementy o jedną pozycję wstecz
        for (int i = 0; i < listSize - index - 1; ++i) {
            currentElement = currentElement->previous;
        }

    }

    //Stwórz new element listy z podanymi parametrami
    ListElement *newListElement = currentElement->next;

    //przypisz new element w odpowiednim miejscu tablicy
    currentElement->next = newListElement->next;
    currentElement->next->previous = newListElement;

    delete[]newListElement;

    //Zmniejsz listSize listy
    listSize--;

}

bool List::checkIfExist(int value) {
    //Sprawdzenie czy lista nie jest pusta
    if (listSize == 0) {
        List::printError("Lista jest pusta.");
        return false;
    }
    currentElement = firstElement;
    //Przeiterowanie po elementach listy i przyrownanie valuei do szukanej
    for (int i = 0; i < listSize; i++) {
        if (currentElement->value == value) {
            cout << "Wartośc znaleziona na pozycji " << i << endl;
            return true;
        }
        currentElement = currentElement->next;
    }
    //Jesli funckja dalej chodzi tzn ze nie bylo wczesniejszego returna i nie znaleziono elementu
    cout << "Nie znaleziono valuei w liscie." << endl;
    return false;
}

void List::clean() {
    List::firstElement = NULL;
    List::currentElement = NULL;
    List::lastElement = NULL;
    List::listSize = 0;
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
