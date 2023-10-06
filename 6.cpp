// c++ 6.cpp && ./a.out | tee 6.txt
#include <cmath>
#include <iostream>

double factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// 1) Implement your function instead of arctan
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

// Compute and print values of myfunc and C++ analog
int main() {
    const int n = 5;
    double x[n]; // 2) static array of arguments x
    for (int i = 0; i < n; i++ )
        x[i] = 0.1 * (i+1); // x=0.1,0.2,...,0.5
    double *fmy = new double[n]; // 3) dynamic array for results of myfunc(x)
    double *std = new double[n]; // results of standard C++ analog of myfunc
    for (int i = 0; i < n; i++ ) {
        fmy[i] = mycosh(x[i]); // your function myfunc
        std[i] = cosh(x[i]);   // C++ analog of myfunc
    }
    // output the result of standard deviation
    double dev = 0.0;
    for (int i = 0; i < n; i++ ) {
        double diff = std::abs(fmy[i] - std[i]); // 4) difference
        std::cout << i << ") mycosh(x=" << x[i] << ")=" << fmy[i]
                  << " C++ cosh(x=" << x[i] << ")=" << std[i]
                  << " diff=" << fmy[i] << " - " << std[i] << " = " << diff
                  << std::endl; // change C++ function name here
        dev += diff * diff; // 5) compute deviation
    }
    dev = sqrt(dev / n);
    std::cout << "dev = " << dev << std::endl; // print deviation
    return 0;
}