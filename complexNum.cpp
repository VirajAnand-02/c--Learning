#include<iostream>
using namespace std;

class ComxNum{
    public:
    float I;
    float J;
    ComxNum(float i=0, float j=0){
        I = i;
        J = j;
    }
    static ComxNum Add(ComxNum A, ComxNum B){
        return ComxNum(A.I + B.I, A.J + B.J);
    }
    static string ComplexToString(ComxNum num){
        cout << num.I << "i + " << num.J << "j";

    }
};

int main(){
    ComxNum A;
    cout << "Input First complex number >" << endl << "i:  ";
    cin >> A.I;
    cout << "j: ";
    cin >> A.J;

    ComxNum B;
    cout << "Input Second complex number >" << endl << "i:  ";
    cin >> B.I;
    cout << "j: ";
    cin >> B.J;

    cout << "Sum of complex number: " ;
    ComxNum::ComplexToString(ComxNum::Add(A, B));
    
}