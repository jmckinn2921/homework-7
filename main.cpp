
#include "matrixccp.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

    Matrix A(2,2);
    Matrix B(2,3);
    Matrix C(2,3);
    cout << "Enter integers  for Matrix A" << endl;
    A.fill();
    cout << "Enter integers for Matrix B" << endl;
    B.fill();
    cout << "Enter integers for Matrix C" << endl;
    C.fill();

    Matrix D = A + (B * 3) * C.transpose();
    D.print();

    return 0;
}
