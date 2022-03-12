/**
 * @file matrix_generator.cc
 * @author David Arteaga Sánchez (alu0101039664@ull.edu.es)
 * @brief This programs generates a random matrix
 * @version 0.1
 * @date 2022-03-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "matrix_generator.h"

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