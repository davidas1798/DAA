/**
 * @file matrix_generator.h
 * @author David Arteaga Sánchez (alu0101039664@ull.edu.es)
 * @brief This programs generates a random matrix
 * @version 0.1
 * @date 2022-02-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MATRIXPRODUCT_P1_MATRIXGENERATOR_H_
#define MATRIXPRODUCT_P1_MATRIXGENERATOR_H_

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class MatrixGenerator {
    private:
        int min_;
        int max_;
    public:
        MatrixGenerator(const int, const int);
        vector<vector<int>> GenerateMatrix(const int, const int);
};

MatrixGenerator::MatrixGenerator(const int min, const int max) {
    min_ = min;
    max_ = max;
    // Initialize the seed for random numbers
    time_t actual_time;
    srand((unsigned) time(&actual_time));
}

vector<vector<int>> MatrixGenerator::GenerateMatrix(const int m, const int n) {
    vector<vector<int>> final_matrix(m, vector<int>(n, 0)); // m x n zero-initialized matrix

    for(auto& row : final_matrix) {
        for(auto& element : row) {
            element = min_ + rand() / (RAND_MAX / (max_ - min_));
        }
    }

    return final_matrix;
}

#endif // MATRIXPRODUCT_P1_MATRIXGENERATOR_H_
