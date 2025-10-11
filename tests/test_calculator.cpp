#include <cassert>
#include <iostream>
#include <iomanip>
#include "../include/calculator.h"

int main() {
    std::cout << "==================================" << std::endl;
    std::cout << "Running Calculator Unit Tests..." << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << std::endl;

    // Square root
    std::cout << "[TEST 1] Square Root Function" << std::endl;
    double sqrt_result = Calculator::squareRoot(49);
    std::cout << "  Input: 49" << std::endl;
    std::cout << "  Expected: 7" << std::endl;
    std::cout << "  Actual: " << sqrt_result << std::endl;
    assert(sqrt_result == 7);
    std::cout << "  Status: PASSED ✓" << std::endl;
    std::cout << std::endl;

    // Factorial
    std::cout << "[TEST 2] Factorial Function" << std::endl;
    unsigned long long factorial_result = Calculator::factorial(4);
    std::cout << "  Input: 4" << std::endl;
    std::cout << "  Expected: 24" << std::endl;
    std::cout << "  Actual: " << factorial_result << std::endl;
    assert(factorial_result == 24);
    std::cout << "  Status: PASSED ✓" << std::endl;
    std::cout << std::endl;

    // Natural log (approximate)
    std::cout << "[TEST 3] Natural Logarithm Function" << std::endl;
    double log_result = Calculator::naturalLog(2.718280);
    std::cout << "  Input: 2.718280" << std::endl;
    std::cout << "  Expected: ~1.0" << std::endl;
    std::cout << "  Actual: " << std::fixed << std::setprecision(6) << log_result << std::endl;
    std::cout << "  Difference: " << abs(log_result - 1.0) << std::endl;
    assert(abs(log_result - 1.0) < 0.01);
    std::cout << "  Status: PASSED ✓" << std::endl;
    std::cout << std::endl;

    // Power
    std::cout << "[TEST 4] Power Function" << std::endl;
    double power_result = Calculator::power(2, 5);
    std::cout << "  Input: base=2, exponent=5" << std::endl;
    std::cout << "  Expected: 32" << std::endl;
    std::cout << "  Actual: " << power_result << std::endl;
    assert(power_result == 32);
    std::cout << "  Status: PASSED ✓" << std::endl;
    std::cout << std::endl;

    std::cout << "==================================" << std::endl;
    std::cout << "All tests passed! ✓✓✓✓" << std::endl;
    std::cout << "Total Tests: 4 | Passed: 4 | Failed: 0" << std::endl;
    std::cout << "==================================" << std::endl;
    
    return 0;
}