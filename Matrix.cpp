#include "matrixccp.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Matrix::Matrix(int rows, int cols) : m_rows(rows), m_cols(cols) {
    matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix& rhs) : m_rows(rhs.m_rows), m_cols(rhs.m_cols) {
    matrix = new int*[m_rows];
    for (int i = 0; i < m_rows; ++i) {
        matrix[i] = new int[m_cols];
        for (int j = 0; j < m_cols; j++) {
            matrix[i][j] = rhs.matrix[i][j];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& rhs) {
    if (this == &rhs) return *this;

    for (int i = 0; i < m_rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    m_rows = rhs.m_rows;
    m_cols = rhs.m_cols;

    matrix = new int*[m_rows];
    for (int i = 0; i < m_rows; i++) {
        matrix[i] = new int[m_cols];
        for (int j = 0; j < m_cols; j++) {
            matrix[i][j] = rhs.matrix[i][j];
        }
    }

    return *this;
}

Matrix::~Matrix() {
    for (int i = 0; i < m_rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

Matrix Matrix::operator+(const Matrix& rhs) const {
    if (!addCheck(rhs)) {
        throw std::invalid_argument("Matrix sizes incompatible for addition");
    }

    Matrix sum(m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            sum.matrix[i][j] = this->matrix[i][j] + rhs.matrix[i][j];
        }
    }

    return sum;
}

Matrix Matrix::operator*(const Matrix& rhs) const {
    if (!multCheck(rhs)) {
        throw std::invalid_argument("Matrix sizes incompatible for multiplication");
    }

    Matrix product(m_rows, rhs.m_cols);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < rhs.m_cols; j++) {
            product.matrix[i][j] = 0;
            for (int k = 0; k < m_cols; k++) {
                product.matrix[i][j] += this->matrix[i][k] * rhs.matrix[k][j];
            }
        }
    }

    return product;
}

Matrix Matrix::operator*(const int rhs) const {
    Matrix result(m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            result.matrix[i][j] = matrix[i][j] * rhs;
        }
    }

    return result;

}

Matrix Matrix::transpose() const {
    Matrix flipped(m_cols, m_rows);
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            flipped.matrix[j][i] = matrix[i][j];
        }
    }
    return flipped;
}

bool Matrix::addCheck(const Matrix& rhs) const {
    return (this->m_rows == rhs.m_rows) && (this->m_cols == rhs.m_cols);
}

bool Matrix::multCheck(const Matrix& rhs) const {
    return this->m_cols == rhs.m_rows;
}

void Matrix::fill() {
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            cout << "Enter integer for row " << i << ", col " << j << ": ";
            cin >> matrix[i][j];
        }
    }
}

void Matrix::print() const {
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
