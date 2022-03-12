/**
 * @file matrix_product.cc
 * @author David Arteaga Sánchez (alu0101039664@ull.edu.es)
 * @brief Classes based on Strategy pattern to calculate the product of two matrices
 * @version 0.1
 * @date 2022-03-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "matrix_product.h"

/**
 * @brief Calculates the product of two matrix first by cols and then by rows
 * @return A vector of vectors (matrix) with the result of the operation
 * 
 */
vector<vector<int>> ColsAndRows::Product(vector<vector<int>>& matrix_a, vector<vector<int>>& matrix_b) {
    const int m = matrix_a.size();  // rows of first matrix
    const int n = matrix_a[0].size();   // cols of first matrix
    const int t = matrix_b.size();  // rows of second matrix
    const int p = matrix_b[0].size();   //cols of second matrix
    if(n != t)
        throw invalid_argument("Rows of the first matrix must coincide with cols of the second one");

    vector<vector<int>> final_matrix(m, vector<int>(p, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < p; j++) {
            for(int k = 0; k < n; k++) {
                final_matrix[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }

    return final_matrix;
}

/**
 * @brief Calculates the product of two matrix first by rows and then by cols
 * @return A vector of vectors (matrix) with the result of the operation
 * 
 */
vector<vector<int>> RowsAndCols::Product(vector<vector<int>>& matrix_a, vector<vector<int>>& matrix_b) {
    const int m = matrix_a.size();  // rows of first matrix
    const int n = matrix_a[0].size();   // cols of first matrix
    const int t = matrix_b.size();  // rows of second matrix
    const int p = matrix_b[0].size();   //cols of second matrix
    if(n != t)
        throw invalid_argument("Rows of the first matrix must coincide with cols of the second one");

    vector<vector<int>> final_matrix(m, vector<int>(p, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < p; j++) {
            for(int k = 0; k < n; k++) {
                final_matrix[j][i] += matrix_a[j][k] * matrix_b[k][i];
            }
        }
    }
    
    return final_matrix;
}