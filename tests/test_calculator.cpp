#include <cassert>
#include <iostream>
#include "../include/calculator.h"

int main() {
    // Square root
    assert(Calculator::squareRoot(25) == 5);

    // Factorial
    assert(Calculator::factorial(5) == 120);

    // Natural log (approximate)
    assert(abs(Calculator::naturalLog(2.71828) - 1.0) < 0.01);

    // Power
    assert(Calculator::power(2, 3) == 8);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}