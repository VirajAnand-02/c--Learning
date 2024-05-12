#include <iostream>
#include <vector>

using namespace std;

class test {
public:
    int marks;
    test(int m) : marks(m) {}
    
    // Display roll number if student appears in both physics and math
    void displayRollIfBothSubjects(const string& name, int roll) const {
        if (marks != 0) {
            cout << "Student " << name << " with roll number " << roll << " appeared in both physics and math." << endl;
        }
    }
};

class math : public test {
public:
    math(int marks) : test(marks) {}
};

class physics : public test {
public:
    physics(int marks) : test(marks) {}
};

class Student {
public:
    int roll;
    std::string name;
    math M;
    physics PHY;

    Student(int roll, const string& name, int mathMarks, int physicsMarks) 
        : roll(roll), name(name), M(mathMarks), PHY(physicsMarks) {}

    // Display roll number if student appears in both physics and math
    void displayRollIfBothSubjects() const {
        if (M.marks != 0 && PHY.marks != 0) {
            cout << "Student " << name << " with roll number " << roll << " appeared in both physics and math." << endl;
        }
    }
};

int main() {
    // Create a vector to store students
    vector<Student> students;

    // Add students to the vector
    students.push_back(Student(1, "Alice", 85, 90));
    students.push_back(Student(2, "Bob", 75, 80));
    students.push_back(Student(3, "Charlie", 0, 90)); // Student appears only in physics
    students.push_back(Student(4, "David", 85, 0));   // Student appears only in math

    // Display roll numbers of students who appeared in both physics and math
    cout << "Students who appeared in both physics and math:" << endl;
    for (const auto& student : students) {
        student.displayRollIfBothSubjects();
    }

    return 0;
}
