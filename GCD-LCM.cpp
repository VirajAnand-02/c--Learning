#include<iostream>
using namespace std;

long long gcd(long long int a, long long int b) { 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
 
long long lcm(int a, int b) { 
    return (a / gcd(a, b)) * b; 
}

int main(){
    int a = 98, b = 56;
    cout << "GCD of " << a << " and " << b << " is "
         << gcd(a, b) << endl;
    
    cout << "LCM of " << a << " and " << b << " is "
         << lcm(a, b);
         
    return 0;
}