// gcc 5.cpp && ./a.out | tee mycosh.txt
#include <cmath>
#include <iostream>

double factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Implement your function instead of arctan
// (see table of functions and your No in the student's list)
double mycosh(double x) {
    double sum = 1, xx = x * x; // x^2 for double
    double current = 0;
    for (int n = 1; n < 10; n++ ) {
        current = xx / factorial(2 * n);
        sum += current;
        xx  *= x * x; // we need to increase as x^2, but for double
        //<-- break if accuracy |val| < 1e-4 is reached
        if(fabs(current) < 1e-4) {
            break;
        }
    }
    return sum;
}

// Compute and print values of myfunc(x) and C++ analog, x=0.1,0.2,...,0.5
int main() {
    for (double x = 0.1; x <= 0.5; x += 0.1) {
        std::cout   << "my cosh(" << x << ")=" << mycosh(x)
                << " vs. C++ cosh(" << x << ")=" << cosh(x) << std::endl;
    }
    
    return 0;
}