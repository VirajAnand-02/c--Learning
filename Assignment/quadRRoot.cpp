#include<iostream>
using namespace std;
#include<math.h>

class Roots {
public:
    float x1;
    float x2;
    Roots(float x1, float x2) : x1(x1), x2(x2) { }
    ~Roots() {
        delete this;
    }

    void show() {
        cout << "Roots: " << x1 << ", " << x2 << endl;
    }
};
class Quadratic {
public:
    float a;
    float b;
    float c;
    Quadratic(float a, float b, float c) : a(a), b(b), c(c) { }

    float discri() {
        return (b * b) - (4 * a * c);
    }

    Roots* roots() {
        float D = this->discri();
        if (D < 0) {
            throw D;
        }
        else {
            float x1 = (-b + sqrt(D)) / (2 * a);
            float x2 = (-b - sqrt(D)) / (2 * a);
            return new Roots(x1, x2);
        }
    }

};

int main() {
    Quadratic eqn(2, -1, 6);
    try {
        eqn.roots()->show();
    }
    catch (float e) {
        cout << "Negative Determinant : Imaganary Roots : " << e << '\n';
    }

}