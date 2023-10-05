// c++ 7.cpp && ./a.out | tee 7.txt
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

double factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

class Point
{
  private:
    double x, y;
  public:
    Point() : x(0), y(0) {}
    Point(double x, double y) {
        this->x = x; 
        this->y = y;
    }
    double dist(Point p) {
        double d;
        // 1) set d to be the distance to point p:
        d = sqrt((p.x - this->x) * (p.x - this->x) + (p.y - this->y) * (p.y - this->y));
        return d;
    }
    void print() {
        cout << "Coords x: " << x << " y: " << y << endl;
    }
};

class Mesh
{
  private:
    vector< vector< Point > > M;
  public:
    Mesh(int nx, int ny) {
        M.resize(nx);
        for (int i=0; i<nx; i++) M[i].resize(ny);
        for (int i=0; i<nx; i++) {
            for (int j=0; j<ny; j++) {
                double x = static_cast<float>(i) / static_cast<float>(nx - 1); // 2) put x on segment [0;1]
                double y = static_cast<float>(j) / static_cast<float>(ny - 1); // 2) put y on segment [0;1]
                Point p(x,y);
                M[i][j] = p;
            }
        }
    }
    double dist(int i, int j, Point p) {
        return M[i][j].dist(p);
    }
    void print(int i, int j) {
        M[i][j].print();
    }
    void print() {
        int nx = M.size();
        int ny = M[0].size();
        cout << "Mesh: Nx = " << nx << " Ny = " << ny << endl;
        M[0][0].print(); // 3) print left-bottom corner here
        M[1][1].print(); // some point is printed
        M[nx-1][ny-1].print(); // right-top corner is printed
    }
};

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

int main()
{
    int nx = 11, ny = 21;
    Mesh M(nx,ny);
    M.print();
    // We need to subtract a 1 because of acosh return values
    double x = mycosh(0.7) - 1; // 5) fit your x to (0;1)
    double y = mycosh(0.9) - 1; // 5) fit your y to (0;1)
    Point p(x,y);
    p.print();
    double dmin = M.dist(0,0,p);
    for (int i=0; i<nx; i++) {
        for (int j=0; j<ny; j++) {
            double d = M.dist(i,j,p);
            if (dmin > d) {
                dmin = d;
                cout << "dmin = " << dmin << " ";
                M.print(i,j);
            }
        }
    }
    cout << "Mesh point nearest to your point p is found."  << endl;
    return 0;
}