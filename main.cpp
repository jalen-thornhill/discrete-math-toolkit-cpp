/*
File Name: main.cpp
Author: Jalen Thornhill
Created: 2026-07-19
Last Modified: 2026-07-19
*/

#include <iostream>
#include "SetOperations.hpp"

using namespace std;

int main() {

   int choice;

do {
    cout << "\nMain Menu\n"
            << "1. Set Operations\n"
            << "2. Relation Checker\n"
            << "3. Function Checker\n"
            << "4. Euclidean Algorithm\n"
            << "5. Sequence Calculator\n"
            << "6. Matrix Operations\n"
            << "7. Exit\n"
            << "Enter your choice: ";

    while(!(cin >> choice) || choice < 1 || choice > 7) {
        cout << "that... that isn't between 1 and 7... let's try this again";

        cin.clear();
        cin.ignore(10000, '\n');
    }


    switch (choice) {
        case 1:
            cout << "Set Operations selected.\n";
            SetOperations setOps;
            setOps.setMenu();
            break;
        case 2:
            cout << "Relation Checker selected.\n";
            break;
        case 3:
            cout << "Function Checker selected.\n";
            break;
        case 4:
            cout << "Euclidean Algorithm selected.\n";
            break;
        case 5:
            cout << "Sequence Calculator selected.\n";
            break;
        case 6:
            cout << "Matrix Operations selected.\n";
            break;
        case 7:
            cout << "Exiting the program.  See you later, Goodbye\n";
            break;
        default:
            cout << "that... that isn't between 1 and 7... let's try this again\n";
    }


} while (choice != 7);
    return 0;
}
