// c++ 5.cpp && ./a.out | tee 5.txt
#include <cmath>
#include <iostream>

// Implement your function instead of arctan
// (see table of functions and your No in the student's list)
double myfunc(double x) {
    double sum = 0, sig = 1, xx = x;
    for (int n = 1; n < 10; n++ ) {
        sum += sig * xx / (2 * n - 1);
        sig *= -1;
        xx  *= x * x;
        //<-- break if accuracy |val| < 1e-4 is reached
    }
    return sum;
}

// Compute and print values of myfunc(x) and C++ analog, x=0.1,0.2,...,0.5
int main() {
    double x = 0.1;
    std::cout << "my arctg(" << x << ")=" << myfunc(x)
              << " vs. C++ atan(x)=" << atan(x) << std::endl;
    return 0;
}