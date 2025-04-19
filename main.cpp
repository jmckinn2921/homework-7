
#include "matrixccp.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

    Matrix A(2,2);
    Matrix B(2,3);
    Matrix C(2,3);

    A.fill();
    B.fill();
    C.fill();

    Matrix D = A + (B * 3) * C.transpose();
    D.print();








    return 0;
}
