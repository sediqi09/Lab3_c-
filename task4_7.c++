#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    string name;
    vector<int> grades;

public:
    // Constructor that initializes only the name and sets grades as an empty vector
    Student(string studentName)
        : name(studentName), grades() {}

    // Constructor that initializes both name and grades
    Student(string studentName, vector<int> studentGrades)
        : name(studentName), grades(studentGrades) {}

    // Method to return the string representation of the student
    string toString() const {
        string result = name + ": [";
        if (grades.empty()) {
            result += "No grades available";
        } else {
            for (size_t i = 0; i < grades.size(); ++i) {
                result += to_string(grades[i]);
                if (i < grades.size() - 1) {
                    result += ", ";
                }
            }
        }
        result += "]";
        return result;
    }
};

int main() {
    vector<int> vasyaGrades = {3, 4, 5};
    Student vasya("Vasya", vasyaGrades);
    
    Student maxim("Maxim");
    
    cout << "Vasya: " << vasya.toString() << endl;
    cout << "Maxim: " << maxim.toString() << endl;

    return 0;
}