#include "../include/calculator.h"

double Calculator::squareRoot(double x) {
    if (x < 0) throw std::invalid_argument("Square root of negative number not allowed.");
    return std::sqrt(x);
}

unsigned long long Calculator::factorial(int n) {
    if (n < 0) throw std::invalid_argument("Factorial of negative number not defined.");
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) result *= i;
    return result;
}

double Calculator::naturalLog(double x) {
    if (x <= 0) throw std::invalid_argument("Natural log undefined for non-positive values.");
    return std::log(x);
}

double Calculator::power(double base, double exp) {
    return std::pow(base, exp);
    // return 1;
}
