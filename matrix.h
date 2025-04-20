#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int m_rows;
    int m_cols;
    int** matrix;
} Matrix;


Matrix createMatrix(int rows, int cols);
void clearMatrix(Matrix* m);
void fillMatrix(Matrix* m);
void printMatrix(const Matrix* m);

Matrix addMatrix(const Matrix* a, const Matrix* b);
Matrix MultMatrix(const Matrix* a, const Matrix* b);
Matrix transpose(const Matrix* m);
Matrix scalarMult(const Matrix* m, int scalar);
int canAdd(const Matrix* a, const Matrix* b);
int canMult(const Matrix* a, const Matrix* b);








#endif