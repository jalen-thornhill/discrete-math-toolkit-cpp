/*
File Name: Relations.hpp
Author: Jalen Thornhill
Created: 2026-07-19
Last Modified: 2026-07-26
*/

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Relation checker declarations will be added here.

class Relations{
    public:
        void relationMenu();

        bool isReflexive(const vector<pair<int, int>>& relation, int elementsInSet);
        bool isSymmetric(const vector<pair<int, int>>& relation);
        bool isTransitive(const vector<pair<int, int>>& relation);
        bool isEquivalence(const vector<pair<int, int>>& relation, int elementsInSet);
};
