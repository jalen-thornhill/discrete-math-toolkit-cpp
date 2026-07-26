/*
File Name: Sequences.cpp
Author: Jalen Thornhill
Created: 2026-07-19
Last Modified: 2026-07-26
*/

#include "Sequences.hpp"

void Sequences::sequenceMenu() {
    int choice;

    do {
        cout << "\nSequence Calculator\n"
                << "1. Arithmetic Progression\n"
                << "2. Geometric Progression\n"
                << "3. Return to Main Menu\n"
                << "Enter your choice: ";

        while (!(cin >> choice)) {
            cout << "Please enter a number: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        switch (choice) {
            case 1: {
                int firstTerm, commonDifference, numberOfTerms;

                cout << "Enter the first term: ";
                while (!(cin >> firstTerm)) {
                    cout << "Please enter a number: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                cout << "Enter the common difference: ";
                while (!(cin >> commonDifference)) {
                    cout << "Please enter a number: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                cout << "Enter the number of terms: ";
                while (!(cin >> numberOfTerms)) {
                    cout << "Please enter a number: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

               if(numberOfTerms <= 0){
                cout << "Number of terms must be greater than 0 :P"<< "\n";
                break;
               }
            

                vector<int> sequence = generateArithmeticSequence(firstTerm, commonDifference, numberOfTerms);

                displaySequence(sequence);
                break;
            }
            case 2: {
                int firstTerm, commonRatio, numberOfTerms;

                cout << "Enter the first term: ";
                while (!(cin >> firstTerm)) {
                    cout << "Please enter a number: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                cout << "Enter the common ratio: ";
                while (!(cin >> commonRatio)) {
                    cout << "Please enter a number: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                cout << "Enter the number of terms: ";
                while (!(cin >> numberOfTerms)) {
                    cout << "Please enter a number: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                if(numberOfTerms <= 0){
                cout << "Number of terms must be greater than 0 :P"<< "\n";
                break;
               }

                vector<int> sequence = generateGeometricSequence(firstTerm,commonRatio,numberOfTerms);

                displaySequence(sequence);
                break;
            }
            case 3:
                cout << "Returning to Main Menu.\n";
                break;
            default:
                cout << "that.. That wasn't a number listed :(" << "\n";
                break;
        }
    } while (choice != 3);
}

vector<int> Sequences::generateArithmeticSequence(int firstTerm, int commonDifference,int numberOfTerms) {
    vector<int> sequence;
    int num = firstTerm;
    sequence.push_back(num);

    for(size_t i = 1; i < numberOfTerms; i++) {
        
        num += commonDifference;
        sequence.push_back(num);
    }   

    return sequence;
}

vector<int> Sequences::generateGeometricSequence(int firstTerm, int commonRatio,int numberOfTerms) {
    vector<int> sequence;
    int num = firstTerm;
    sequence.push_back(num);

    for(size_t i = 1; i < numberOfTerms; i++) {
        
        num *= commonRatio;
        sequence.push_back(num);
    }

    

    return sequence;
}

void Sequences::displaySequence(const vector<int>& sequence) {
    cout << "Sequence: ";

    for (size_t i = 0; i < sequence.size(); i++) {
        cout << sequence[i];

        if (i + 1 < sequence.size()) {
            cout << ", ";
        }
    }

    cout << "\n";
}
