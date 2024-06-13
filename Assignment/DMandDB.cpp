#include<iostream>
using namespace std;

class DB;

class DM {
private:
    float meter;
    float cm;
public:
    DM(float m, float c) : meter(m), cm(c) {}
    float toCentimeters() const {
        return meter * 100 + cm;
    }
    friend void add(const DM& DMObj, const DB& DBObj);
};

class DB {
private:
    float feet;
    float inch;
public:
    DB(float f, float i) : feet(f), inch(i) {}
    float toCentimeters() const {
        return (feet * 30.48) + (inch * 2.54);
    }
    friend void add(const DM& DMObj, const DB& DBObj);
};

void add(const DM& DMObj, const DB& DBObj) {
    float totalCm = DMObj.toCentimeters() + DBObj.toCentimeters();
    cout << "Total length in centimeters: " << totalCm << " cm" << endl;
}

int main() {
    DM dmObj(5, 50);  // 5 meters and 50 centimeters
    DB dbObj(16, 12); // 16 feet and 12 inches
    add(dmObj, dbObj);
    return 0;
}