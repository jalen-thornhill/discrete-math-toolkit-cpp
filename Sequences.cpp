/*
File Name: Sequences.cpp
Author: Jalen Thornhill
Created: 2026-07-19
Last Modified: 2026-07-26
*/

#include "Sequences.hpp"
#include <limits>

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
                long long firstTerm, commonDifference;
                int numberOfTerms;

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

                vector<long long> sequence = generateArithmeticSequence(firstTerm, commonDifference, numberOfTerms);

                if (!sequence.empty()) displaySequence(sequence);
                break;
            }
            case 2: {
                long long firstTerm, commonRatio;
                int numberOfTerms;

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

                vector<long long> sequence = generateGeometricSequence(firstTerm, commonRatio, numberOfTerms);

                if (!sequence.empty()) displaySequence(sequence);
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

vector<long long> Sequences::generateArithmeticSequence(long long firstTerm, long long commonDifference, int numberOfTerms) {
    vector<long long> sequence;
    long long num = firstTerm;
    sequence.push_back(num);

    for(int i = 1; i < numberOfTerms; i++) {
        if (commonDifference > 0 && num > numeric_limits<long long>::max() - commonDifference) {
            cout << "The sequence became too large to calculate.\n";
            sequence.clear();
            return sequence;
        }

        if (commonDifference < 0 && num < numeric_limits<long long>::min() - commonDifference) {
            cout << "The sequence became too large to calculate.\n";
            sequence.clear();
            return sequence;
        }

        num += commonDifference;
        sequence.push_back(num);
    }

    return sequence;
}

vector<long long> Sequences::generateGeometricSequence(long long firstTerm, long long commonRatio, int numberOfTerms) {
    vector<long long> sequence;
    long long num = firstTerm;
    sequence.push_back(num);

    for(int i = 1; i < numberOfTerms; i++) {
        bool tooLarge = false;

        if (num == -1 && commonRatio == numeric_limits<long long>::min()) tooLarge = true;
        else if (commonRatio == -1 && num == numeric_limits<long long>::min()) tooLarge = true;
        else if (num > 0 && commonRatio > 0 && num > numeric_limits<long long>::max() / commonRatio) tooLarge = true;
        else if (num > 0 && commonRatio < 0 && commonRatio < numeric_limits<long long>::min() / num) tooLarge = true;
        else if (num < 0 && commonRatio > 0 && num < numeric_limits<long long>::min() / commonRatio) tooLarge = true;
        else if (num < 0 && commonRatio < 0 && num < numeric_limits<long long>::max() / commonRatio) tooLarge = true;

        if (tooLarge) {
            cout << "The sequence became too large to calculate.\n";
            sequence.clear();
            return sequence;
        }

        num *= commonRatio;
        sequence.push_back(num);
    }

    return sequence;
}

void Sequences::displaySequence(const vector<long long>& sequence) {
    cout << "Sequence: ";

    for (size_t i = 0; i < sequence.size(); i++) {
        cout << sequence[i];

        if (i + 1 < sequence.size()) {
            cout << ", ";
        }
    }

    cout << "\n";
}
