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

#include <vector>

using namespace std;

template <class T>
class MatrixGenerator {
    public:
        vector<vector<T>> GenerateMatrix(const T, const T);
};
