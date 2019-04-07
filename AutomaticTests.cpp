//
// Created by Mateusz sliwka on 2019-04-04.
//

#include "AutomaticTests.h"
#include <iostream>
#include <fstream>
#include "ManualTests.h"
#include "Array.h"
#include "Timer.h"
#include "List.h"
#include "Heap.h"
#include "Tree.h"
using namespace std;

void AutomaticTests::printError(string message) {
    cout << "[ERROR] " + message << endl;
}

void AutomaticTests::testArray() {
    srand(time(NULL));
    Timer timer;
    Array array;
    fstream fileIn, fileOut;
    string pathIn, pathOut, lineIn1;
    int x = 1, value, index;
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
        cout << "0. Wyjscie\n";
        cout << "========================\n";
        cout << "Wybieram opcje: ";
        cin >> x;
        cout << "Podaj sciezkie pliku zawierajacego dane wejsciowe: ";
        cin >> pathIn;
        cout << "Podaj miejsce docelowe zapisu wyniku testow: ";
        cin >> pathOut;
        fileIn.open("../Data/" + pathIn, ios::in);
        fileOut.open("../Results/Array/"+pathOut, ios::out);
        if (fileIn.is_open())
            cout << "Pomyslnie otwarto plik wejsciowy" << endl;
        else {
            AutomaticTests::printError("Blad odczytu pliku z danymi wejsciowymi.");
            return;
        }
        if (fileOut.is_open())
            cout << "Pomyslnie otwarto plik wyjsciowy" << endl;
        else {
            AutomaticTests::printError("Blad odczytu pliku z danymi wyjsciowymi.");
            return;
        }
        switch (x) {
            case 1:
                cout << "*** TEST AUTOMATYCZNY ***\n";
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    timer.timerStart();
                    array.addToTheBeginning(atoi(lineIn1.c_str()));
                    timer.timerStop();
                    fileOut << timer.execTime() << endl;
                }
                fileIn.close();
                fileOut.close();
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                break;
            case 2:
                cout << "*** TEST AUTOMATYCZNY ***\n";
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    timer.timerStart();
                    array.addToTheEnd(atoi(lineIn1.c_str()));
                    timer.timerStop();
                    fileOut << timer.execTime() << endl;
                }
                fileIn.close();
                fileOut.close();
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                break;
            case 3:
                cout << "*** TEST AUTOMATYCZNY ***\n";
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    timer.timerStart();
                    array.addOnPosition(atoi(lineIn1.c_str()), rand() % array.arraySize);
                    timer.timerStop();
                    fileOut << timer.execTime() << endl;
                }
                fileIn.close();
                fileOut.close();
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciowym.\n";
                break;
            case 4:
                cout << "*** TEST AUTOMATYCZNY ***\n";
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    array.addToTheBeginning(atoi(lineIn1.c_str()));
                }
                while (array.arraySize != 0) {
                    timer.timerStart();
                    array.removeFirstOne();
                    timer.timerStop();
                    fileOut << timer.execTime() << endl;
                }
                fileIn.close();
                fileOut.close();
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                break;
            case 5:
                cout << "*** TEST AUTOMATYCZNY ***\n";
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    array.addToTheBeginning(atoi(lineIn1.c_str()));
                }
                while (array.arraySize != 0) {
                    timer.timerStart();
                    array.removeLastOne();
                    timer.timerStop();
                    fileOut << timer.execTime() << endl;
                }
                fileIn.close();
                fileOut.close();
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                break;
            case 6:
                cout << "*** TEST AUTOMATYCZNY ***\n";
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    array.addToTheBeginning(atoi(lineIn1.c_str()));
                }
                while (array.arraySize != 0) {
                    timer.timerStart();
                    array.removeElement(rand() % array.arraySize);
                    timer.timerStop();
                    fileOut << timer.execTime() << endl;
                }
                fileIn.close();
                fileOut.close();
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                break;
            case 7:
                cout << "*** TEST AUTOMATYCZNY ***\n";
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    array.addToTheBeginning(atoi(lineIn1.c_str()));
                }
                for (int i = 0; i < array.arraySize; i++) {
                    timer.timerStart();
                    array.checkIfExist(rand() % 2000000);
                    timer.timerStop();
                    fileOut << timer.execTime() << endl;
                }
                fileIn.close();
                fileOut.close();
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                break;
            case 8:
                cout << "*** TEST AUTOMATYCZNY ***\n";
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    array.addToTheBeginning(atoi(lineIn1.c_str()));
                }
                timer.timerStart();
                array.printArray();
                timer.timerStop();
                fileOut << timer.execTime() << endl;
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                break;
            case 0:
                break;
            default:
                printError("Wybrales zla opcje. Sprobuj ponownie.");
        }
    }
}

void AutomaticTests::testList() {
    srand(time(NULL));
    Timer timer;
    List list;
    fstream fileIn, fileOut;
    string pathIn, pathOut, lineIn1;
    int x = 1, value, index;
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
        cout << "0. Wyjscie\n";
        cout << "========================\n";
        cout << "Wybieram opcje: ";
        cin >> x;
        cout << "Podaj sciezkie pliku zawierajacego dane wejsciowe: ";
        cin >> pathIn;
        cout << "Podaj miejsce docelowe zapisu wyniku testow: ";
        cin >> pathOut;
        fileIn.open("../Data/" + pathIn, ios::in);
        fileOut.open("../Results/List/"+pathOut, ios::out);
        if (fileIn.is_open())
            cout << "Pomyslnie otwarto plik wejsciowy" << endl;
        else {
            AutomaticTests::printError("Blad odczytu pliku z danymi wejsciowymi.");
            return;
        }
        if (fileOut.is_open())
            cout << "Pomyslnie otwarto plik wyjsciowy" << endl;
        else {
            AutomaticTests::printError("Blad odczytu pliku z danymi wyjsciowymi.");
            return;
        }
        switch (x) {
            case 1:
                cout << "*** TEST AUTOMATYCZNY ***\n";
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    timer.timerStart();
                    list.addToTheBeginning(atoi(lineIn1.c_str()));
                    timer.timerStop();
                    fileOut << timer.execTime() << endl;
                }
                fileIn.close();
                fileOut.close();
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                break;
            case 2:
                cout << "*** TEST AUTOMATYCZNY ***\n";
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    timer.timerStart();
                    list.addToTheEnd(atoi(lineIn1.c_str()));
                    timer.timerStop();
                    fileOut << timer.execTime() << endl;
                }
                fileIn.close();
                fileOut.close();
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                break;
            case 3:
                cout << "*** TEST AUTOMATYCZNY ***\n";
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    timer.timerStart();
                    list.addOnPosition(atoi(lineIn1.c_str()), rand() % list.listSize);
                    timer.timerStop();
                    fileOut << timer.execTime() << endl;
                }
                fileIn.close();
                fileOut.close();
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                break;
            case 4:
                cout << "*** TEST AUTOMATYCZNY ***\n";
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    list.addToTheBeginning(atoi(lineIn1.c_str()));
                }
                while (list.listSize != 0) {
                    timer.timerStart();
                    list.removeFirstOne();
                    timer.timerStop();
                    fileOut << timer.execTime() << endl;
                }
                fileIn.close();
                fileOut.close();
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                break;
            case 5:
                cout << "*** TEST AUTOMATYCZNY ***\n";
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    list.addToTheBeginning(atoi(lineIn1.c_str()));
                }
                while (list.listSize != 0) {
                    timer.timerStart();
                    list.removeLastOne();
                    timer.timerStop();
                    fileOut << timer.execTime() << endl;
                }
                fileIn.close();
                fileOut.close();
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                break;
            case 6:
                cout << "*** TEST AUTOMATYCZNY ***\n";
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    list.addToTheBeginning(atoi(lineIn1.c_str()));
                }
                while (list.listSize != 0) {
                    timer.timerStart();
                    list.removeElement(rand() % list.listSize);
                    timer.timerStop();
                    fileOut << timer.execTime() << endl;
                }
                fileIn.close();
                fileOut.close();
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                break;
            case 7:
                cout << "*** TEST AUTOMATYCZNY ***\n";
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    list.addToTheBeginning(atoi(lineIn1.c_str()));
                }
                for (int i = 0; i < list.listSize; i++) {
                    timer.timerStart();
                    list.checkIfExist(rand() % 2000000);
                    timer.timerStop();
                    fileOut << timer.execTime() << endl;
                }
                fileIn.close();
                fileOut.close();
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                break;
            case 8:
                cout << "*** TEST AUTOMATYCZNY ***\n";
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    list.addToTheBeginning(atoi(lineIn1.c_str()));
                }
                timer.timerStart();
                list.printList();
                timer.timerStop();
                fileOut << timer.execTime() << endl;
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                break;
            case 0:
                break;
            default:
                printError("Wybrales zla opcje. Sprobuj ponownie.");
        }
    }
}


void AutomaticTests::testHeap() {
    srand(time(NULL));
    Timer timer;
    Heap heap;
    fstream fileIn, fileOut;
    string pathIn, pathOut, lineIn1;
    int x = 1, value;
    while (x != 0) {
        cout << "\n=== Wybierz czynnosc ===\n";
        cout << "1. Dodaj element do kopca\n";
        cout << "2. Usun element z kopca\n";
        cout << "3. Wyszukaj wartosc w kopcu\n";
        cout << "4. Wyswietl kopiec\n";
        cout << "0. Wyjscie\n";
        cout << "========================\n";
        cout << "Wybieram opcje: ";
        cin >> x;
        cout << "Podaj sciezkie pliku zawierajacego dane wejsciowe: ";
        cin >> pathIn;
        cout << "Podaj miejsce docelowe zapisu wyniku testow: ";
        cin >> pathOut;
        fileIn.open("../Data/" + pathIn, ios::in);
        fileOut.open("../Results/Heap/"+pathOut, ios::out);
        if (fileIn.is_open())
            cout << "Pomyslnie otwarto plik wejsciowy" << endl;
        else {
            AutomaticTests::printError("Blad odczytu pliku z danymi wejsciowymi.");
            return;
        }
        if (fileOut.is_open())
            cout << "Pomyslnie otwarto plik wyjsciowy" << endl;
        else {
            AutomaticTests::printError("Blad odczytu pliku z danymi wyjsciowymi.");
            return;
        }

        switch (x) {
            case 1:

                while (!fileIn.eof()) {

                    fileIn >> lineIn1;
                    timer.timerStart();
                    heap.add(atoi(lineIn1.c_str()));
                    timer.timerStop();
                    fileOut << timer.execTime() << endl;
                }

                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                fileOut.close();
                break;
            case 2:
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    heap.add(atoi(lineIn1.c_str()));
                }
                fileIn.open("../Data/" + pathIn, ios::in);
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    timer.timerStart();
                    heap.remove(atoi(lineIn1.c_str()));
                    timer.timerStop();
                    fileOut << timer.execTime() << endl;
                }
                fileIn.close();
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                fileOut.close();
                break;
            case 3:
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    heap.add(atoi(lineIn1.c_str()));
                }
                for (int i = 0; i < heap.size; i++) {
                    timer.timerStart();
                    heap.checkIfExist(rand() % 200000);
                    fileOut << timer.execTime() << endl;
                }
                fileIn.close();
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                fileOut.close();
                break;
            case 4:
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    heap.add(atoi(lineIn1.c_str()));
                }
                timer.timerStart();
                heap.printHeap();
                timer.timerStop();
                fileOut << timer.execTime() << endl;
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                fileOut.close();
            case 0:
                break;
            default:
                printError("Wybrales zla opcje. Sprobuj ponownie.");
        }
    }
}


void AutomaticTests::testTree() {
    srand(time(NULL));
    Timer timer;
    Tree tree;
    fstream fileIn, fileOut;
    string pathIn, pathOut, lineIn1;
    int x = 1, value;
    while (x != 0) {
        cout << "\n=== Wybierz czynnosc ===\n";
        cout << "1. Dodaj element do drzewa\n";
        cout << "2. Usun element z drzewa\n";
        cout << "3. Wyszukaj wartosc w drzewie\n";
        cout << "4. Wyswietl drzewo\n";
        cout << "0. Wyjscie\n";
        cout << "========================\n";
        cout << "Wybieram opcje: ";
        cin >> x;
        cout << "Podaj sciezkie pliku zawierajacego dane wejsciowe: ";
        cin >> pathIn;
        cout << "Podaj miejsce docelowe zapisu wyniku testow: ";
        cin >> pathOut;
        fileIn.open("../Data/" + pathIn, ios::in);
        fileOut.open("../Results/Tree/" + pathOut, ios::out);
        if (fileIn.is_open())
            cout << "Pomyslnie otwarto plik wejsciowy" << endl;
        else {
            AutomaticTests::printError("Blad odczytu pliku z danymi wejsciowymi.");
            return;
        }
        if (fileOut.is_open())
            cout << "Pomyslnie otwarto plik wyjsciowy" << endl;
        else {
            AutomaticTests::printError("Blad odczytu pliku z danymi wyjsciowymi.");
            return;
        }

        switch (x) {
            case 1:

                while (!fileIn.eof()) {

                    fileIn >> lineIn1;
                    timer.timerStart();
                    tree.add(atoi(lineIn1.c_str()));
                    timer.timerStop();
                    fileOut << timer.execTime() << endl;
                }
                fileIn.close();
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                fileOut.close();
                break;
            case 2:
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    tree.add(atoi(lineIn1.c_str()));
                }
                fileIn.close();
                fileIn.open("../Data/" + pathIn, ios::in);
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    timer.timerStart();
                    tree.remove(atoi(lineIn1.c_str()));
                    timer.timerStop();
                    fileOut << timer.execTime() << endl;
                }
                fileIn.close();
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                fileOut.close();
                break;
            case 3:
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    tree.add(atoi(lineIn1.c_str()));
                }
                for (int i = 0; i < tree.size; i++) {
                    timer.timerStart();
                    tree.checkIfExists(rand() % 200000);
                    timer.timerStop();
                    fileOut << timer.execTime() << endl;
                }
                fileIn.close();
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                fileOut.close();
                break;
            case 4:
                while (!fileIn.eof()) {
                    fileIn >> lineIn1;
                    tree.add(atoi(lineIn1.c_str()));
                }
                timer.timerStart();
                tree.print();
                timer.timerStop();
                fileOut << timer.execTime() << endl;
                cout << "Test zakonczony. Wynik znajduje sie we wskazanym pliku wyjsciosym.\n";
                fileOut.close();
            case 0:
                break;
            default:
                printError("Wybrales zla opcje. Sprobuj ponownie.");
        }
    }
}