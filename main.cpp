#include <iostream>
#include "ManualTests.h"
#include "AutomaticTests.h"

using namespace std;

void printError(string message) {
    cout << "[BlĄD] " + message << endl;
}

bool if_automaticTest() {
    int x = 1000;
    while (x != 0) {
        cout << "\n*** Wybierz rodzaj testowania ***\n";
        cout << "1. Testowanie automatyczne\n";
        cout << "2. Testowanie manualne\n";
        cout << "************************\n";
        cout << "Wybieram opcje: ";
        cin >> x;
        switch (x) {
            case 1:
                return true;
            case 2:
                return false;
            default:
                printError("Wybrales zlą opcje. Sprobuj ponownie.");
                break;
        }
    }
    return false;
}

int main() {
    ManualTests manualTests;
    AutomaticTests automaticTests;
    //Menu wyboru struktury
    int x = 100;
    while (x != 0) {
        cout << "\n=== Wybierz strukture ===\n";
        cout << "1. Tablica dynamiczna\n";
        cout << "2. Lista\n";
        cout << "3. Kopiec binarny\n";
        cout << "4. Drzewo czerwono-czarne\n";
        cout << "0. Zamknij program\n";
        cout << "========================\n";
        cout << "Wybieram opcje: ";
        cin >> x;
        switch (x) {
            case 1:
                if (if_automaticTest())
                    automaticTests.testArray();
                else
                    manualTests.testArray();
                break;
            case 2:
                if (if_automaticTest())
                    automaticTests.testList();
                else
                    manualTests.testList();
                break;
            case 3:
                if (if_automaticTest())
                    automaticTests.testHeap();
                else
                    manualTests.testHeap();
                break;
            case 4:
                if (if_automaticTest())
                    automaticTests.testTree();
                else
                    manualTests.testTree();
                break;
            case 0:
                break;
            default:
                printError("Wybrales zlą opcje. Sprobuj ponownie.");
        }
    }

}