/*
File Name: Relations.cpp
Author: Jalen Thornhill
Created: 2026-07-19
Last Modified: 2026-07-26
*/

#include "Relations.hpp"

// Relation checker implementations will be added here.

void Relations::relationMenu() {
    // Implementation for relation menu
    int choice;
    int elementsInSet, numberOfPairs, pairFirst, pairSecond;

    cout << "Enter the number of elements in the set: ";
    while(!(cin >> elementsInSet) || elementsInSet < 0) {

        cout << "Please enter a non-negative integer ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Enter the number of ordered pairs in the relation: ";
    while(!(cin >> numberOfPairs) || numberOfPairs < 0 || numberOfPairs > elementsInSet * elementsInSet) {
        cout << "Please enter a number between 0 and " << elementsInSet * elementsInSet << ": ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    vector<pair<int, int>> relation;

    cout << "Enter the ordered pairs (two integers separated by a space):\n";
    for (int i = 0; i < numberOfPairs; i++) {
        cout << "Pair " << (i + 1) << ": ";
        while(!(cin >> pairFirst >> pairSecond) || pairFirst < 0 || pairFirst >= elementsInSet || pairSecond < 0 || pairSecond >= elementsInSet) {
            cout << "Please enter valid indices (between 0 and " << (elementsInSet - 1) << "): ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        relation.push_back(make_pair(pairFirst, pairSecond));
    }


    do {
        cout << "\nRelation Checker Menu\n"
                << "1. Check Reflexivity\n"
                << "2. Check Symmetry\n"
                << "3. Check Transitivity\n"
                << "4. Check Equivalence\n"
                << "5. Back to Main Menu\n"
                << "Enter your choice: ";

        while(!(cin >> choice) || choice < 1 || choice > 5) {
            cout << "that... that isn't between 1 and 5... let's try this again";

            cin.clear();
            cin.ignore(10000, '\n');
        }

        switch (choice) {
            case 1:
                cout << "Check Reflexivity selected.\n";
                // Call the function to check reflexivity here
                if (isReflexive(relation, elementsInSet)) {
                    cout << "The relation is reflexive.\n";
                } else {
                    cout << "The relation is not reflexive.\n";
                }
                break;
            case 2:
                cout << "Check Symmetry selected.\n";
                // Call the function to check symmetry here
                if (isSymmetric(relation)) {
                    cout << "The relation is symmetric.\n";
                } else {
                    cout << "The relation is not symmetric.\n";
                }
                break;
            case 3:
                cout << "Check Transitivity selected.\n";
                // Call the function to check transitivity here
                if (isTransitive(relation)) {
                    cout << "The relation is transitive.\n";
                } else {
                    cout << "The relation is not transitive.\n";
                }
                break;
            case 4:
                cout << "Check Equivalence selected.\n";
                // Call the function to check equivalence here
                if (isEquivalence(relation, elementsInSet)) {
                    cout << "The relation is an equivalence relation.\n";
                } else {
                    cout << "The relation is not an equivalence relation.\n";
                }
                break;
            case 5:
                cout << "Returning to Main Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);


 
}


bool Relations::isReflexive(const vector<pair<int, int>>& relation, int elementsInSet) {
    // Implementation for checking reflexivity
    for (int i = 0; i < elementsInSet; ++i) {
        if (find(relation.begin(), relation.end(), make_pair(i, i)) == relation.end()) {
            return false; // Not reflexive if (i, i) is not found
        }
    }
    return true; // Reflexive if all (i, i) are found
}

bool Relations::isSymmetric(const vector<pair<int, int>>& relation) {
    // Implementation for checking symmetry
for (const auto& duo : relation){
    int first = duo.first;
    int second = duo.second;

    if (find(relation.begin(), relation.end(), make_pair(second, first)) == relation.end()){
        return false; // Not symmetric if (second, first) is not found
    }
}
return true; // Symmetric if all (second, first) are found
}

bool Relations::isTransitive(const vector<pair<int, int>>& relation) {

    for(const auto& duo1 : relation){
        for(const auto& duo2 : relation){
            if(duo1.second == duo2.first){
                if(find(relation.begin(), relation.end(), make_pair(duo1.first, duo2.second))  == relation.end()) return false;
            }
        }
    }
    return true;
}


bool Relations::isEquivalence(const vector<pair<int, int>>& relation, int elementsInSet) {
    // Implementation for checking equivalence
    return isReflexive(relation, elementsInSet) && isSymmetric(relation) && isTransitive(relation);
}
