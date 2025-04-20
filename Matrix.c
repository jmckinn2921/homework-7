#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix createMatrix(int rows, int cols) {
    Matrix m;
    m.m_rows = rows;
    m.m_cols = cols;
    m.matrix = malloc(rows * sizeof(int*)); 
    for (int i = 0; i < rows; i ++) {
        m.matrix[i] = malloc (cols * sizeof(int));
    }
    return m;
}

void clearMatrix(Matrix* m) {
    for (int i = 0; i < m->m_rows; i++) {
        free (m->matrix[i]);
    }
    free(m->matrix);
}


void printMatrix(const Matrix* m) {
    for (int i = 0; i < m->m_rows; i++) {
        for (int j = 0; j < m->m_cols; j++) {
            printf("%d ", m->matrix[i][j]);
        }
        printf("\n");
    }
}

void fillMatrix(Matrix* m) {
    for (int i = 0; i < m->m_rows; i++) {
        for (int j = 0; j < m->m_cols; j++) {
            printf("Enter element [%d][%d]: " , i, j); 
            scanf("%d", &m->matrix[i][j]); 
        }
    }
}

Matrix addMatrix(const Matrix* a, const Matrix* b) {
    Matrix result = createMatrix(a->m_rows, a->m_cols);
    for (int i = 0; i < a->m_rows; i++) {
        for (int j = 0; j < a->m_cols; j++) {
            result.matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
        }
    }
    return result;
}

Matrix scalarMult(const Matrix* m, int scaler) {
    Matrix result = createMatrix(m->m_rows, m->m_cols);
    for (int i = 0; i < m->m_rows; i++) {
        for (int j = 0; j < m->m_cols; j++) {
            result.matrix[i][j] = m->matrix[i][j] * scaler;
        }
    }
    return result; 
}

Matrix transpose(const Matrix* m) {
    Matrix result = createMatrix(m->m_cols, m->m_rows);
    for (int i = 0; i < m->m_rows; i++) {
        for (int j = 0; j < m->m_cols; j++) {
            result.matrix[j][i] = m->matrix[i][j];
        }
    }
    return result;
}


Matrix MultMatrix(const Matrix* a, const Matrix* b) {
    Matrix result = createMatrix(a->m_rows, b->m_cols);
    for (int i = 0; i < a->m_rows; i++) {
        for (int j = 0; j < b->m_cols; j++) {
            result.matrix[i][j] = 0;
        
            for (int k = 0; k < a->m_cols; k++) {
                result.matrix[i][j] += a->matrix[i][k] * b->matrix[k][j];
            }
        }
    }
    
    return result;
}


int canAdd(const Matrix* a, const Matrix* b) {
    return (a->m_rows == b->m_rows && a->m_cols == b->m_cols);
}

int canMult(const Matrix* a, const Matrix* b) {
    return (a->m_cols == b->m_rows);
}