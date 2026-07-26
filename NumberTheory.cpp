/*
File Name: NumberTheory.cpp
Author: Jalen Thornhill
Created: 2026-07-19
Last Modified: 2026-07-26
*/

#include "NumberTheory.hpp"

void NumberTheory::euclideanAlgorithmMenu() {
    int firstInteger, secondInteger;

    while (true) {
        cout << "Enter the first integer: ";
        while (!(cin >> firstInteger)) {
            cout << "Please enter an integer: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        cout << "Enter the second integer: ";
        while (!(cin >> secondInteger)) {
            cout << "Please enter an integer: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        if (firstInteger == 0 && secondInteger == 0) {
            cout << "The GCD of 0 and 0 is undefined. Please try again.\n";
            continue;
        }

        break;
    }

    if (firstInteger < 0) {
        firstInteger = -firstInteger;
    }

    if (secondInteger < 0) {
        secondInteger = -secondInteger;
    }

    displayEuclideanSteps(firstInteger, secondInteger);

    int gcd = calculateGCD(firstInteger, secondInteger);
    cout << "\nGCD: " << gcd << "\n";
}

int NumberTheory::calculateGCD(int num1, int num2) {
    int remainder = 0;
    while(num2 != 0){
         
         remainder = num1 % num2;

        num1 = num2;
        num2 = remainder;

    
        
    }
    return num1;
}

void NumberTheory::displayEuclideanSteps(int num1, int num2) {
    int quotient = 0, remainder = 0;

    while (num2 != 0) {
        quotient = num1 / num2;
        remainder = num1 % num2;

        cout << num1 << " = " << num2 << " * " << quotient << " + " << remainder << "\n";

        num1 = num2;
        num2 = remainder;
    }
}
