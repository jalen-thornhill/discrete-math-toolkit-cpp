/*
File Name: Matrices.hpp
Author: Jalen Thornhill
Created: 2026-07-19
Last Modified: 2026-07-26
*/

#pragma once

#include <iostream>

using namespace std;

class Matrices {
    public:
        void matrixMenu();
        void readMatrix(int matrix[2][2], char matrixName);
        void displayMatrix(const int matrix[2][2]);
        void addMatrices(const int matrixA[2][2], const int matrixB[2][2], int result[2][2]);
        void subtractMatrices(const int matrixA[2][2], const int matrixB[2][2], int result[2][2]);
        void multiplyMatrices(const int matrixA[2][2], const int matrixB[2][2], int result[2][2]);
};
