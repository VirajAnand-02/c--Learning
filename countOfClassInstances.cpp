#include<iostream>
using namespace std;

class Count{
    public:
    static int counter;
    Count(){
        counter++;
    }
    ~Count(){
        counter--;
    }
    static int getObjCount(){
        cout << "total no of object instance : " << counter;
        return counter;
    }
};

int Count::counter = 0; // init counter

int main(){
    Count hemlo;
    Count obj1;
    Count obj2;
    Count::getObjCount();
}