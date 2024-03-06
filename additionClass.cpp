#include<iostream>
using namespace std;

class Sum{
    private:
    float a=0;
    float b=0;

    public:
    void setA(float A){
        a = A;
    }
    void setB(float B){
        b = B;
    }
    float sumAB(){
        return a+b;
    }
};

int main(){
    Sum sum;

    cout << "Set A : ";
    float a;
    cin >> a;
    cout << "Set B : ";
    float b;
    cin >> b;
    sum.setA(a);
    sum.setB(b);
    cout << "Sum: " << sum.sumAB() << endl;
    
}