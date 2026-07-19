/*
File Name: SetOperations.hpp
Author: Jalen Thornhill
Created: 2026-07-19
Last Modified: 2026-07-19
*/

#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


class SetOperations {
public:
    void setMenu();
    
    set<int> unionOp(vector<int> setA, vector<int> setB);

    set<int> intersectionOp(vector<int> setA, vector<int> setB);

    set<int> differenceOp(vector<int> setA, vector<int> setB);

    vector<pair<int, int>> cartesianProductOp(vector<int> setA, vector<int> setB);
};
