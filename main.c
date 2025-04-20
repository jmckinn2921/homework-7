#include <stdio.h>
#include "matrix.h"

int main() {

    Matrix A = createMatrix(2, 2);
    Matrix B = createMatrix(2, 3);
    Matrix C = createMatrix(2, 3);

    printf("Fill Matrix A:\n");
    fillMatrix(&A);

    printf("Fill Matrix B:\n");
    fillMatrix(&B);

    printf("Fill Matrix C:\n");
    fillMatrix(&C);

    // transpose c Matrix
    Matrix C_transposed = transpose(&C);

    // Scale b
    Matrix B_scaled = scalarMult(&B, 3);

    Matrix product = MultMatrix(&B_scaled, &C_transposed);

    Matrix D = addMatrix(&A, &product);

    printMatrix(&D);



    clearMatrix(&A);
    clearMatrix(&B);
    clearMatrix(&C);
    clearMatrix(&product);
    clearMatrix(&D);


   
    return 0; 
}