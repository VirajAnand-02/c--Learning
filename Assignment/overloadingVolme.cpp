#include<iostream>
using namespace std;

class CalcVolume {
public:
    static float Calc(float x);
    static float Calc(float r, float h, bool cone);
};

float CalcVolume::Calc(float x) {
    return x * x * x;

}

float CalcVolume::Calc(float r, float h, bool cone) {
    if (cone) {
        return (1 / 3) * (22 / 7) * r * r * h;
    }
    return (22 / 7) * r * r * h;
}


int main() {
    int op;
    float vol;
    float height;
    float radius;
    float side;
    cout << "To calculate volume of : \n1) Cube\n2) Cone \n3) Cylinder \n> ";
    cin >> op;

    switch (op) {
    case 1:
        cout << "Enter side length : ";
        cin >> side;
        vol = CalcVolume::Calc(side);
        break;
    case 2:
        cout << "Enter height : ";
        cin >> height;
        cout << "Enter radius : ";
        cin >> radius;
        vol = CalcVolume::Calc(radius, height, true);
        break;
    case 3:
        cout << "Enter height : ";
        cin >> height;
        cout << "Enter radius : ";
        cin >> radius;
        vol = CalcVolume::Calc(radius, height, false);
        break;

    default:
        cout << "Invlid Option";
        exit(1);
        break;
    }

    cout << "Volume : " << vol << endl;

}