#include <iostream>
using namespace std;

int sqrtInteger(int num) {
    if (num < 0) {
        cout << "Error: Negative number";
        return -1;  // Indicative of an error in input
    }
    if (num == 0 || num == 1) return num;
    
    int start = 1, end = num, ans;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (mid <= num / mid) {
            start = mid + 1;
            ans = mid;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "The square root of " << num << " is approximately " << sqrtInteger(num) << endl;
    return 0;
}
