//
// Created by Mateusz Śliwka on 2019-04-04.
//

#include "Array.h"
#include <iostream>

using namespace std;


//Tworzenie obiektu tablicy, inicjalizacja zmiennych
Array::Array() {
    Array::arraySize = 0;
    Array::headPtr = NULL;
}

//Destruktor obiektu tablicy, zwolnienie pamięci
Array::~Array() {
    if (headPtr != NULL)
        delete[] headPtr;
}

void Array::clean() {
    Array::arraySize = 0;
    Array::headPtr = NULL;
}

void Array::printError(string message) {
    cout << "[ERROR] " + message << endl;
}

void Array::addToTheBeginning(int value) {
    //Stworzenie tablicy o rozmiareze o 1 wiekszym
    int *newHeadPtr = new int[arraySize + 1];
    //Przypisanie wstawianego elementu jako pierwszy tablicy
    newHeadPtr[0] = value;
    //Przepisanie starej tablicy do nowej
    for (int i = 0; i < arraySize; i++)
        newHeadPtr[i + 1] = headPtr[i];
    //Usunięcie starej tablicy
    delete headPtr;
    //Przypisanie do wskaznika na glowe tablicy nowej tablicy
    headPtr = newHeadPtr;
    //Zwiekszenie rozmiaru tablicy o 1
    arraySize++;
}

void Array::addToTheEnd(int value) {
    //Stworzenie tablicy o rozmiareze o 1 wiekszym
    int *newHeadPtr = new int[arraySize + 1];
    //Przypisanie wstawianego elementu jako ostatni tablicy
    newHeadPtr[arraySize] = value;
    //Przepisanie starej tablicy do nowej
    for (int i = 0; i < arraySize; i++)
        newHeadPtr[i] = headPtr[i];
    //Usunięcie starej tablicy
    delete headPtr;
    //Przypisanie nowej tablicy do wskaznika na głowę
    headPtr = newHeadPtr;
    //Zwiększenie rozmiaru tablicy o 1
    arraySize++;
}

void Array::addOnPosition(int value, int index) {
    //Sprawdzenie pozycji do wpisania - czy jest wolna, czy jest realna
    if (index < 0 || index > arraySize) {
        Array::printError("Nie ma takiej pozycji w tablicy");
    } else {
        //Stworzenie tablicy o rozmiarze o 1 wiekszym
        int *newHeadPtr = new int[arraySize + 1];
        //Dodanie elementu na danej pozycji
        newHeadPtr[index] = value;
        //Przepisanie danych ze starej tablicy do nowej
        for (int i = 0; i < arraySize; i++)
            if (i >= index)
                newHeadPtr[i + 1] = headPtr[i];
            else if(i<index)
                newHeadPtr[i] = headPtr[i];
        //Usunięcie starej tablicy
        delete headPtr;
        //Przypisanie nowej tablicy do wskaznika na głowę
        headPtr = newHeadPtr;
        //Zwiększenie rozmiaru tablicy o 1
        arraySize++;
    }
}

void Array::removeLastOne() {
    //Sprawdzenie czy tablica nie jest pusta
    if (arraySize < 1)
        printError("Tablica jest pusta, nie mozna z niej nic usunąć.");
    else {
        //Stworzenie tablicy o rozmiarze o 1 mniejszym
        int *newHeadPtr = new int[arraySize - 1];
        //Przepisanie danych ze starej tablicy do nowej
        for (int i = 0; i < arraySize - 1; i++)
            newHeadPtr[i] = headPtr[i];
        //Usunięcie starej tablicy
        delete headPtr;
        //Przypisanie nowej tablicy do wskaznika na głowę
        headPtr = newHeadPtr;
        //Zmniejszenie rozmiaru tablicy o 1
        arraySize--;
    }
}

void Array::removeFirstOne() {
    //Sprawdzenie czy tablica nie jest pusta
    if (arraySize < 1)
        printError("Tablica jest pusta, nie mozna z niej nic usunąć.");
    else {
        //Stworzenie tablicy o rozmiarze o 1 mniejszym
        int *newHeadPtr = new int[arraySize - 1];
        //Przepisanie danych ze starej tablicy do nowej
        for (int i = 1; i < arraySize; i++)
            newHeadPtr[i - 1] = headPtr[i];
        //Usunięcie starej tablicy
        delete headPtr;
        //Przypisanie nowej tablicy do wskaznika na głowę
        headPtr = newHeadPtr;
        //Zmniejszenie rozmiaru tablicy o 1
        arraySize--;
    }
}

void Array::removeElement(int index) {
    if (arraySize < 0 || index < 0 || index >= arraySize) {
        printError("W tablicy nie ma takiej pozycji.");
    } else {
        //Stworzenie tablicy o rozmiarze o 1 mniejszym
        int *newHeadPtr = new int[arraySize - 1];
        //Przepisanie danych ze starej tablicy do nowej oprocz pozycji index
        for (int i = 0; i < arraySize; i++)
            if (i < index)
                newHeadPtr[i] = headPtr[i];
            else if (i > index)
                newHeadPtr[i - 1] = headPtr[i];
        //Usunięcie starej tablicy
        delete headPtr;
        //Przypisanie nowej tablicy do wskaznika na głowę
        headPtr = newHeadPtr;
        //Zmniejszenie rozmiaru tablicy o 1
        arraySize--;
    }
}

bool Array::checkIfExist(int value) {
    //Sprawdzenie czy tablica nie jest pusta
    if (arraySize < 1)
        printError("Tablica jest pusta, nie mozesz w niej niczego szukac.");
    else {
        //Przeszukiwanie tablicy, porownanie jej kazdego elementu do value
        for (int i = 0; i < arraySize; i++)
            //Jesli wartosc tablicy = value to znaczy ze znalezlismy ta wartosc w tablicy
            if (headPtr[i] == value) {
                cout << "Wartośc znajduje się na pozycji " << i << endl;
                return true;
            }
        //Jesli funkcja dalej dziala to znaczy ze wartosc nie zostala znaleziona wiec komunikujemy to
        cout << "Wartość nie została znaleziona w tablicy." << endl;
        return false;
    }
    return false;
}

void Array::printArray() {
    //Sprawdzenie czy tablica nie jest pusta
    if (arraySize < 1)
        printError("Tablica jest pusta.");
    else {
        //Wypisanie kazdego elementu tablicy poprzedzonego [indeksem pozycji]
        cout << "Aktualna tablica: " << endl;
        for (int i = 0; i < arraySize; i++)
            cout << " [" << i << "]" << headPtr[i] << endl;
    }
}
