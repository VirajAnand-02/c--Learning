#include<iostream>
using namespace std;
#include <vector>

class test {
public:
    int roll;
    int marks;

};

class math :test {
public:
    math(int roll, int marks) {
        this->roll = roll;
        this->marks = marks;
    }
};

class physics :test {
public:
    physics(int roll, int marks) {
        this->roll = roll;
        this->marks = marks;
    }
};

class Student {
public:
    int roll;
    // std::string name;
    std::vector<test> numbers; // Assuming you have a 'test' class defined somewhere
};

int main() {
    Student student[10];
    for(int i = 0; i< 10; i++){
        student[i].roll = i+1;
        test toPush = math(student[i].roll, i*50);
        student[i].numbers.push_back(toPush);
    }
}