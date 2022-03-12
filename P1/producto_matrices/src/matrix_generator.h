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

#endif // MATRIXPRODUCT_P1_MATRIXGENERATOR_H_
