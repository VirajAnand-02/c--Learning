#include<iostream>
using namespace std;
#define NUMS_QUANTITY 3
#include <vector>

int maxNum(vector<int> arr) {
    int max = arr[0];
    for (int i = 0; i < arr.size(); i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    vector<int> numbers;
    for (int i = 0; i < NUMS_QUANTITY;i++) {
        cout << "Enter num " << i+1 << " ) ";
        int tmp;
        cin >> tmp;
        numbers.push_back(tmp);
    }
    cout << "Max number is: " << maxNum(numbers) << endl;

}