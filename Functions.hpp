/*
File Name: Functions.hpp
Author: Jalen Thornhill
Created: 2026-07-19
Last Modified: 2026-07-26
*/

#pragma once

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Functions{
    public:
        void functionsMenu();
        bool isValid(const vector<pair<int, int>>& mappings);
        bool isInjective(const vector<pair<int, int>>& mappings);
        bool isBijective(const vector<pair<int, int>>& mappings);
};
