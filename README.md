## Authoring
- Justin McKinnon
- Affililation: University of Maryland Baltimore County, Cmsc 313, 4/19/25, 9:30




## Purpose of software
This program is a a set a different files in two different coding languages (c and c++) which perform elementry matrix operatrations. 
- Matrix Creation, additions, multiplication, scalar multiplication, and transposition
- Memory management in both




## Files

Main.cpp: Test driver to show matrix operations
Matrix.cpp: Implementation of Matrix class
Matrix.h: Declaration of Matrix class
Makefile: Builds both c and c++ files, runs them, and cleans them.


Main.c: Test driver to show matrix operations
Matrix.c: Implementation of matrix functions
Matrix.h: Declaration of Matrix functions


## Build Instructions

To compile, run...

make

To run files...

"make run_c" for c

"make run_cpp: for c++

To clean files...
make clean



## Testing Methodology
Both versions will ask the user to fill out three different matricies. The size of all matrcies are given so the user just needs to input what they want each row and colum to be. After the user inputs the data, the program will then compute the expression D = A + (3 * B) * C.transpose().
After doing that, the program will output that result.

## Additional information
No additional information
