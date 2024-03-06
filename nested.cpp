#include<iostream>
using namespace std;
class grt{
    public:
    static int greater(int a, int b){
        if(a>b){
            return a;
        }
        return b;
    }
};

int main(){
    int a = 1;
    int b = 2;
    int c = 3;
    cout << "input numbers (a) : ";
    cin >> a;
    cout << "input numbers (b) : ";
    cin >> b;
    cout << "input numbers (c) : ";
    cin >> c;
    cout << grt::greater(a, grt::greater(b, c));

}