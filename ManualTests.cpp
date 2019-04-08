//
// Created by Mateusz sliwka on 2019-04-04.
//

#include "ManualTests.h"
#include "Timer.h"
#include "Array.h"
#include "List.h"
#include "Heap.h"
#include "Tree.h"
#include <iostream>

using namespace std;

void ManualTests::printError(string message) {
    cout << "[ERROR] " + message << endl;
}

void ManualTests::testArray() {
    bool displayArray;
    Timer timer;
    Array array;
    srand(time(NULL));
    int ilosccyfr=0,maxcyfra=0;
    int x, value, index;
    while (x != 0) {
        cout << "\n=== Wybierz czynnosc ===\n";
        cout << "1. Dodaj element na poczatek tablicy\n";
        cout << "2. Dodaj element na koniec tablicy\n";
        cout << "3. Dodaj element w podane miejsce\n";
        cout << "4. Usun pierwszy element tablicy\n";
        cout << "5. Usun ostatni element tablicy\n";
        cout << "6. Usun element tablicy na danej pozycji\n";
        cout << "7. Wyszukaj element w tablicy\n";
        cout << "8. Pokaz zawartosc tablicy\n";
        cout<<"9. Dodaj dana ilosc losowych cyfr\n";
        cout << "0. Wyjscie\n";
        cout << "========================\n";
        cout << "Wybieram opcje: ";
        cin >> x;
        switch (x) {
            case 1:
                cout << "Podaj wartosc elementu: ";
                cin >> value;
                timer.timerStart();
                array.addToTheBeginning(value);
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 2:
                cout << "Podaj wartosc elementu: ";
                cin >> value;
                timer.timerStart();
                array.addToTheEnd(value);
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";

                break;
            case 3:
                cout << "Podaj wartosc elementu: ";
                cin >> value;
                cout << "Podaj pozycje na ktora chcesz go wpisac: ";
                cin >> index;
                timer.timerStart();
                array.addOnPosition(value, index);
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 4:
                cout << "Procedura rozpoczeta. Trwa usuwanie pierwszego elementu\n";
                timer.timerStart();
                array.removeFirstOne();
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 5:
                cout << "Procedura rozpoczeta. Trwa usuwanie ostatniego elementu\n";
                timer.timerStart();
                array.removeLastOne();
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 6:
                cout << "Podaj pozycje z ktorej chcesz usunac element: ";
                cin >> index;
                timer.timerStart();
                array.removeElement(index);
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 7:
                cout << "Podaj wartosc szukanego elementu: ";
                cin >> value;
                timer.timerStart();
                array.checkIfExist(value);
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 8:
                timer.timerStart();
                array.printArray();
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 0:
                break;
            case 9:
                cout<<"Ile cyfr chcesz dodac? ";
                cin>>ilosccyfr;
                cout<<"Jaka maksymalna cyfra? ";
                cin>>maxcyfra;
                for(int i=0;i<ilosccyfr;i++)
                    array.addToTheBeginning(rand()%maxcyfra);
                break;
            default:
                printError("Wybrales zla opcje. Sprobuj ponownie.");
        }
    }

}

void ManualTests::testList() {
    bool displayArray;
    srand(time(NULL));
    Timer timer;
    int ilosccyfr,maxcyfra;
    List list;
    int x, value, index;
    while (x != 0) {
        cout << "\n=== Wybierz czynnosc ===\n";
        cout << "1. Dodaj element na poczatek listy\n";
        cout << "2. Dodaj element na koniec listy\n";
        cout << "3. Dodaj element w podane miejsce\n";
        cout << "4. Usun pierwszy element listy\n";
        cout << "5. Usun ostatni element listyy\n";
        cout << "6. Usun element listy na danej pozycji\n";
        cout << "7. Wyszukaj element w listy\n";
        cout << "8. Pokaz zawartosc listy\n";
        cout<<"9. Dodaj dana ilosc losowych cyfr\n";
        cout << "0. Wyjscie\n";
        cout << "========================\n";
        cout << "Wybieram opcje: ";
        cin >> x;
        switch (x) {
            case 1:
                cout << "Podaj wartosc elementu: ";
                cin >> value;
                timer.timerStart();
                list.addToTheBeginning(value);
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 2:
                cout << "Podaj wartosc elementu: ";
                cin >> value;
                timer.timerStart();
                list.addToTheEnd(value);
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";

                break;
            case 3:
                cout << "Podaj wartosc elementu: ";
                cin >> value;
                cout << "Podaj pozycje na ktora chcesz go wpisac: ";
                cin >> index;
                timer.timerStart();
                list.addOnPosition(value, index);
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 4:
                cout << "Procedura rozpoczeta. Trwa usuwanie pierwszego elementu\n";
                timer.timerStart();
                list.removeFirstOne();
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 5:
                cout << "Procedura rozpoczeta. Trwa usuwanie ostatniego elementu\n";
                timer.timerStart();
                list.removeLastOne();
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 6:
                cout << "Podaj pozycje z ktorej chcesz usunac element: ";
                cin >> index;
                timer.timerStart();
                list.removeElement(index);
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 7:
                cout << "Podaj wartosc szukanego elementu: ";
                cin >> value;
                timer.timerStart();
                list.checkIfExist(value);
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 8:
                timer.timerStart();
                list.printList();
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 0:
                break;
            case 9:
                cout<<"Ile cyfr chcesz dodac? ";
                cin>>ilosccyfr;
                cout<<"Jaka maksymalna cyfra? ";
                cin>>maxcyfra;
                for(int i=0;i<ilosccyfr;i++)
                    list.addToTheBeginning(rand()%maxcyfra);
                break;
            default:
                printError("Wybrales zla opcje. Sprobuj ponownie.");
        }
    }

}

void ManualTests::testHeap() {
    Timer timer;
    int ilosccyfr,maxcyfra;
    Heap heap;
    int x = 1, value;
    srand(time(NULL));
    while (x != 0) {
        cout << "\n=== Wybierz czynnosc ===\n";
        cout << "1. Dodaj element do kopca\n";
        cout << "2. Usun element z kopca\n";
        cout << "3. Wyszukaj wartosc w kopcu\n";
        cout << "4. Wyswietl kopiec\n";
        cout<<"5. Dodaj dana ilosc losowych cyfr\n";
        cout << "0. Wyjscie\n";
        cout << "========================\n";
        cout << "Wybieram opcje: ";
        cin >> x;
        switch (x) {
            case 1:
                cout << "Podaj wartosc do dodania: ";
                cin >> value;
                timer.timerStart();
                heap.add(value);
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 2:
                cout << "Podaj wartosc do usuniecia: ";
                cin >> value;
                timer.timerStart();
                heap.remove(value);
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 3:
                cout << "Podaj wartosc do wyszukania: ";
                cin >> value;
                timer.timerStart();
                heap.checkIfExist(value);
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 4:
                timer.timerStart();
                heap.printHeap();
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 0:
                break;
            case 5:
                cout<<"Ile cyfr chcesz dodac? ";
                cin>>ilosccyfr;
                cout<<"Jaka maksymalna cyfra? ";
                cin>>maxcyfra;
                for(int i=0;i<ilosccyfr;i++)
                    heap.add(rand()%maxcyfra);
                break;
            default:
                printError("Wybrales zla opcje. Sprobuj ponownie.");
        }
    }
}

void ManualTests::testTree() {
    Timer timer;
    int ilosccyfr,maxcyfra;
    Tree tree;
    srand(time(NULL));
    int x = 1, value;
    while (x != 0) {
        cout << "\n=== Wybierz czynnosc ===\n";
        cout << "1. Dodaj element do drzewa\n";
        cout << "2. Usun element z drzewa\n";
        cout << "3. Wyszukaj wartosc w drzewie\n";
        cout << "4. Wyswietl drzewo\n";
        cout<<"5. Dodaj dana ilosc losowych cyfr\n";
        cout << "0. Wyjscie\n";
        cout << "========================\n";
        cout << "Wybieram opcje: ";
        cin >> x;
        switch (x) {
            case 1:
                cout << "Podaj wartosc do dodania: ";
                cin >> value;
                timer.timerStart();
                tree.add(value);
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 2:
                cout << "Podaj wartosc do usuniecia: ";
                cin >> value;
                timer.timerStart();
                tree.remove(value);
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 3:
                cout << "Podaj wartosc do wyszukania: ";
                cin >> value;
                timer.timerStart();
                tree.checkIfExists(value);
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 4:
                timer.timerStart();
                tree.print();
                timer.timerStop();
                cout << "Procedura trwala: " << timer.execTime() << "ns\n";
                break;
            case 0:
                break;
            case 5:
                cout<<"Ile cyfr chcesz dodac? ";
                cin>>ilosccyfr;
                cout<<"Jaka maksymalna cyfra? ";
                cin>>maxcyfra;
                for(int i=0;i<ilosccyfr;i++)
                    tree.add(rand()%maxcyfra);
                break;
            default:
                printError("Wybrales zla opcje. Sprobuj ponownie.");
        }
    }
}