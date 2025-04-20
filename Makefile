# ==== Compilers and Flags ====
CXX = g++
CC = gcc
CXXFLAGS = -Wall -std=c++11
CFLAGS = -Wall -std=c99

# ==== Targets ====
CPP_TARGET = matrix_cpp
C_TARGET = matrix_c

# ==== Object Files ====
CPP_OBJS = main.o Matrix.o
C_OBJS = main_c.o matrix_c.o

# ==== Default Target ====
all: $(CPP_TARGET) $(C_TARGET)

# ==== C++ Build Rules ====
$(CPP_TARGET): main.o Matrix.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp matrixccp.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Matrix.o: Matrix.cpp matrixccp.h
	$(CXX) $(CXXFLAGS) -c Matrix.cpp

# ==== C Build Rules ====
$(C_TARGET): main_c.o matrix_c.o
	$(CC) $(CFLAGS) -o $@ $^

main_c.o: main.c matrix.h
	$(CC) $(CFLAGS) -c -o $@ main.c

matrix_c.o: Matrix.c matrix.h
	$(CC) $(CFLAGS) -c -o $@ Matrix.c

# ==== Run Targets ====
run_cpp: $(CPP_TARGET)
	./$(CPP_TARGET)

run_c: $(C_TARGET)
	./$(C_TARGET)

# ==== Clean ====
clean:
	rm -f *.o $(CPP_TARGET) $(C_TARGET)
