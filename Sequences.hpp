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
        vector<long long> generateArithmeticSequence(long long firstTerm, long long commonDifference, int numberOfTerms);
        vector<long long> generateGeometricSequence(long long firstTerm, long long commonRatio, int numberOfTerms);
        void displaySequence(const vector<long long>& sequence);
};
