#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <cmath>
#include <stdexcept>

class Calculator {
public:
    static double squareRoot(double x);
    static unsigned long long factorial(int n);
    static double naturalLog(double x);
    static double power(double base, double exp);
};

#endif