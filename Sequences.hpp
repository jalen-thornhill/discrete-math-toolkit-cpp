/*
File Name: Sequences.hpp
Author: Jalen Thornhill
Created: 2026-07-19
Last Modified: 2026-07-26
*/

#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Sequences {
    public:
        void sequenceMenu();
        vector<int> generateArithmeticSequence(int firstTerm, int commonDifference, int numberOfTerms);
        vector<int> generateGeometricSequence(int firstTerm, int commonRatio, int numberOfTerms);
        void displaySequence(const vector<int>& sequence);
};
