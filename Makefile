CXX = g++
CXXFLAGS = -std=c++11 -Wall -static
SRC = src/main.cpp src/calculator.cpp
TEST_SRC = tests/test_calculator.cpp src/calculator.cpp
INC = -Iinclude
TARGET = calculator
TEST_TARGET = test_calculator

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(INC) -o $(TARGET) $(SRC)

test: $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(INC) -o $(TEST_TARGET) $(TEST_SRC)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)