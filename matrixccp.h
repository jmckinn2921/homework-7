#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;
class Matrix {
    public:
        Matrix(int rows, int cols);
        Matrix(const Matrix& rhs);
        Matrix& operator=(const Matrix& rhs);
        ~Matrix();

        Matrix operator+(const Matrix& rhs) const;
        Matrix operator*(const Matrix &rhs) const;
        Matrix operator*(const int rhs) const;
        Matrix transpose() const;
        bool addCheck(const Matrix& rhs) const;
        bool multCheck(const Matrix& rhs) const;


        void fill();
        void print() const;

    private:
        int m_rows;
        int m_cols;
        int** matrix;
};


#endif