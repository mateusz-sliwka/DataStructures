//
// Created by Mateusz Śliwka on 2019-04-05.
//

#include "Heap.h"
#include <math.h>
#include <iostream>
#include <string>

#include <cstdlib>

using namespace std;

Heap::Heap() {
    Heap::array = NULL;
    Heap::size = 0;
}

Heap::~Heap() {
    if (Heap::size > 0)
        delete[] array;
}

void Heap::add(int value) {
    //Wykluczamy mozliwosc zduplikowania wartosci w kopcu
    cout << value << endl;
    //Tworzenie nowej tablicy o wiekszym rozmiarze
    int *newArray = new int[size + 1];
    //Przepisanie danych do nowej tablicy
    for (int i = 0; i < size; i++)
        newArray[i] = array[i];
    //Dodanie wartosci do kopca
    newArray[size] = value;
    //Usuniecie starej tablicy
    delete[] array;
    //Zastapienie starej nową
    array = newArray;
    //Przebudowanie na kopiec
    Heap::rebuildHeap();
    size++;

}

void Heap::remove(int value) {
    //Szukam w tablicy wartosci=valiue
    for (int i = 0; i < size; i++) {
        //Szukam wartosci ktora mam usunac
        if (array[i] == value) {
            int *newArray = new int[size - 1];
            //Przepisanie danych do nowej tablicy z pominieciem tej znalezionej
            for (int k = 0; k < size; k++) {
                if (k >= i)
                    newArray[k - 1] = array[k];
                else
                    newArray[k] = array[k];
            }
            //Usuwam stara tablice
            delete[] array;
            //W miejsce starej wpisuje nowa, juz bez tego elementu
            array = newArray;
            //Zmniejszam rozmiar
            size--;
            //Przebudowuje na kopiec
            Heap::rebuildHeap();
            //Zakanczam petle
            return;
        }
    }
}

bool Heap::checkIfExist(int value) {
    //Przeszukuje cala tablice kopca
    for (int i = 0; i < size; i++)
        //Przyrownuje wartosc elementu do value
        if (array[i] == value) {
            cout << "Wartosc znajduje sie w tablicy kopca na pozycji: " << i;
            //Jak znalazlem to zakanczam petle
            return true;
        }
    cout << "Wartosc nie zostala znaleziona w kopcu." << endl;
    return false;
}

void Heap::rebuildHeap() {
    int tmp = 0;
    for (int i = size; 0 < i; i--) {
        if (array[i - 1] < array[i]) {
            tmp = array[i - 1];
            array[i - 1] = array[i];
            array[i] = tmp;
        }
    }
}

void Heap::printHeap() {
    printBT("", "", 0);
}

void Heap::printBT(string sp, string sn, int v) {
    string cr, cl, cp;
    cr = cl = cp = "  ";
    cr="┌─";
    cl="└─";
    cp[0]='|';

    string s;

    if (v < size) {
        s = sp;
        if (sn == cr) s[s.length() - 2] = ' ';
        printBT(s + cp, cr, 2 * v + 2);

        s = s.substr(0, sp.length() - 2);

        cout << s << sn << array[v] << endl;

        s = sp;
        if (sn == cl) s[s.length() - 2] = ' ';
        printBT(s + cp, cl, 2 * v + 1);
    }
}