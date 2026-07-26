/*
File Name: NumberTheory.hpp
Author: Jalen Thornhill
Created: 2026-07-19
Last Modified: 2026-07-26
*/

#pragma once

#include <iostream>

using namespace std;

class NumberTheory {
    public:
        void euclideanAlgorithmMenu();
        int calculateGCD(int num1, int num2);
        void displayEuclideanSteps(int num1, int num2);
};
