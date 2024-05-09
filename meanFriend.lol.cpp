#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;

class RealSet {
private:
    vector<float> arr;
public:
    RealSet(vector<float> arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (count(this->arr.begin(), this->arr.end(), arr[i]) == 0) {
                this->arr.push_back(arr[i]);
            }
        }

        for (float x : this->arr) {
            cout << x << ", ";
        }
        cout << endl;
    }

    friend float mean(RealSet& obj) {
        float summ = 0;
        for (float x : obj.arr) {
            summ += x;
        }
        return summ / obj.arr.size();
    }


};

int main() {
    RealSet a(vector<float> {315.2, 531.6, 531.6, 531.6, 51.55, 0.6561});
    cout << "Average: " << mean(a) << endl;
}