#include <cassert>
#include <iostream>
#include "../include/calculator.h"

int main() {
    // Square root
    assert(Calculator::squareRoot(49) == 7);

    // Factorial
    assert(Calculator::factorial(4) == 24);

    // Natural log (approximate)
    assert(abs(Calculator::naturalLog(2.718280) - 1.0) < 0.01);

    // Power
    assert(Calculator::power(2, 5) == 32);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}