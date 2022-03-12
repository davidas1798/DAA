/**
 * @file matrix_product.h
 * @author David Arteaga Sánchez (alu0101039664@ull.edu.es)
 * @brief Classes based on Strategy pattern to calculate the product of two matrices
 * @version 0.1
 * @date 2022-03-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MATRIXPRODUCT_P1_MATRIXPRODUCT_H_
#define MATRIXPRODUCT_P1_MATRIXPRODUCT_H_

#include <vector>
#include <stdexcept>
#include <iostream>
#include <ctime>

using namespace std;

/**
 * @brief Interface to calculate the product of two matrices
 * 
 */
class MatrixProduct {
    public:
        virtual vector<vector<int>> Product(vector<vector<int>>&, vector<vector<int>>&) = 0;
};

class RowsAndCols: public MatrixProduct {
    public:
        vector<vector<int>> Product(vector<vector<int>>&, vector<vector<int>>&);
};

class ColsAndRows: public MatrixProduct {
    vector<vector<int>> Product(vector<vector<int>>&, vector<vector<int>>&);
};

#endif // MATRIXPRODUCT_P1_MATRIXPRODUCT_H_