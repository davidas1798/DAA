#include "matrix_generator.h"
#include "matrix_product.h"

int main() {
    MatrixGenerator matrix_generator(0, 10);
    MatrixProduct* matrix_product_rows = new RowsAndCols;
    MatrixProduct* matrix_product_cols = new ColsAndRows;

    // 100 x 50 * 50 x 100
    vector<vector<int>> matrix_a = matrix_generator.GenerateMatrix(100, 50);
    vector<vector<int>> matrix_b = matrix_generator.GenerateMatrix(50, 100);

    unsigned t0, t1, t2, t3;
    cout << "100x50 * 50x100" << endl;
    t0 = clock();
    matrix_product_rows->Product(matrix_a, matrix_b);
    t1 = clock();
    double time_rows = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << endl << "Tiempo por filas: " << time_rows << endl;
    t2 = clock();
    matrix_product_cols->Product(matrix_a, matrix_b);
    t3 = clock();
    double time_cols = (double(t3 - t2) / CLOCKS_PER_SEC);
    cout << endl << "Tiempo por columnas: " << time_cols << endl;

    // 500 x 100 * 100 x 500
    matrix_a = matrix_generator.GenerateMatrix(500, 100);
    matrix_b = matrix_generator.GenerateMatrix(100, 500);

    cout << "500x100 * 100x500" << endl;
    t0 = clock();
    matrix_product_rows->Product(matrix_a, matrix_b);
    t1 = clock();
    time_rows = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << endl << "Tiempo por filas: " << time_rows << endl;
    t2 = clock();
    matrix_product_cols->Product(matrix_a, matrix_b);
    t3 = clock();
    time_cols = (double(t3 - t2) / CLOCKS_PER_SEC);
    cout << endl << "Tiempo por columnas: " << time_cols << endl;

    // 1000 x 250 * 250 x 1000
    matrix_a = matrix_generator.GenerateMatrix(1000, 250);
    matrix_b = matrix_generator.GenerateMatrix(250, 1000);

    cout << "1000x250 * 250x1000" << endl;
    t0 = clock();
    matrix_product_rows->Product(matrix_a, matrix_b);
    t1 = clock();
    time_rows = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << endl << "Tiempo por filas: " << time_rows << endl;
    t2 = clock();
    matrix_product_cols->Product(matrix_a, matrix_b);
    t3 = clock();
    time_cols = (double(t3 - t2) / CLOCKS_PER_SEC);
    cout << endl << "Tiempo por columnas: " << time_cols << endl;

    // 1500 x 500 * 500 x 1500
    matrix_a = matrix_generator.GenerateMatrix(1500, 500);
    matrix_b = matrix_generator.GenerateMatrix(500, 1500);

    cout << "1500x500 * 500x1500" << endl;
    t0 = clock();
    matrix_product_rows->Product(matrix_a, matrix_b);
    t1 = clock();
    time_rows = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << endl << "Tiempo por filas: " << time_rows << endl;
    t2 = clock();
    matrix_product_cols->Product(matrix_a, matrix_b);
    t3 = clock();
    time_cols = (double(t3 - t2) / CLOCKS_PER_SEC);
    cout << endl << "Tiempo por columnas: " << time_cols << endl;


    delete matrix_product_rows;
    delete matrix_product_cols;

    return 0;
}