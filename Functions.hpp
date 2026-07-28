/*
File Name: Functions.hpp
Author: Jalen Thornhill
Created: 2026-07-19
Last Modified: 2026-07-27
*/

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Functions{
    public:
        void functionsMenu();
        bool isValid(const vector<pair<int, int>>& mappings, const vector<int>& domain);
        bool isInjective(const vector<pair<int, int>>& mappings, const vector<int>& domain);
        bool isBijective(const vector<pair<int, int>>& mappings, const vector<int>& domain);
};
