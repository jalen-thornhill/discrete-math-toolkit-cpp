/*
File Name: Matrices.cpp
Author: Jalen Thornhill
Created: 2026-07-19
Last Modified: 2026-07-26
*/

#include "Matrices.hpp"

void Matrices::matrixMenu() {
    int choice;
    int matrixA[2][2], matrixB[2][2], result[2][2];

    readMatrix(matrixA, 'A');
    readMatrix(matrixB, 'B');

    cout << "\nMatrix A:\n";
    displayMatrix(matrixA);

    cout << "\nMatrix B:\n";
    displayMatrix(matrixB);

    do {
        cout << "\nMatrix Operations\n"
                << "1. Matrix Addition\n"
                << "2. Matrix Subtraction\n"
                << "3. Matrix Multiplication\n"
                << "4. Return to Main Menu\n"
                << "Enter your choice: ";

        while (!(cin >> choice) || choice < 1 || choice > 4) {
            cout << "that... that isn't between 1 and 4... let's try this again";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        switch (choice) {
            case 1:
                cout << "Matrix Addition selected.\n";
                addMatrices(matrixA, matrixB, result);
                cout << "Result:\n";
                displayMatrix(result);
                break;
            case 2:
                cout << "Matrix Subtraction selected.\n";
                subtractMatrices(matrixA, matrixB, result);
                cout << "Result:\n";
                displayMatrix(result);
                break;
            case 3:
                cout << "Matrix Multiplication selected.\n";
                multiplyMatrices(matrixA, matrixB, result);
                cout << "Result:\n";
                displayMatrix(result);
                break;
            case 4:
                cout << "Returning to Main Menu.\n";
                break;
            default:
                cout << "that... that isn't between 1 and 4... let's try this again\n";
        }
    } while (choice != 4);
}

void Matrices::readMatrix(int matrix[2][2], char matrixName) {
    cout << "Enter Matrix " << matrixName << ":\n";

    for (int row = 0; row < 2; row++) {
        for (int column = 0; column < 2; column++) {
            cout << "Row " << row + 1 << ", Column " << column + 1 << ": ";

            while (!(cin >> matrix[row][column])) {
                cout << "Please enter an integer: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
    }
}

void Matrices::displayMatrix(const int matrix[2][2]) {
    for (int row = 0; row < 2; row++) {
        for (int column = 0; column < 2; column++) {
            cout << matrix[row][column] << "  ";
        }

        cout << "\n";
    }
}

void Matrices::addMatrices(const int matrixA[2][2], const int matrixB[2][2], int result[2][2]) {
    for (int row = 0; row < 2; row++) {
        for (int column = 0; column < 2; column++) {
            result[row][column] = matrixA[row][column] + matrixB[row][column];
        }
    }
}

void Matrices::subtractMatrices(const int matrixA[2][2], const int matrixB[2][2], int result[2][2]) {
    for (int row = 0; row < 2; row++) {
        for (int column = 0; column < 2; column++) {
            result[row][column] = matrixA[row][column] - matrixB[row][column];
        }
    }
}

void Matrices::multiplyMatrices(const int matrixA[2][2], const int matrixB[2][2], int result[2][2]) {
    for (int row = 0; row < 2; row++) {
        for (int column = 0; column < 2; column++) {
            result[row][column] = 0;

            for (int position = 0; position < 2; position++) {
                result[row][column] += matrixA[row][position] * matrixB[position][column];
            }
        }
    }
}
