# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Targets
TARGET = matrix_cpp
OBJS = main.o Matrix.o

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files
main.o: main.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Matrix.o: Matrix.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c Matrix.cpp

# run target
run: $(TARGET)
	./$(TARGET)
# Clean build files
clean:
	rm -f $(TARGET) *.o
