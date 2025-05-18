#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    string name;
    vector<int> grades;

public:
    Student(string studentName, vector<int> studentGrades)
        : name(studentName), grades(studentGrades) {}

    string toString() const {
        string result = name + ": [";
        for (size_t i = 0; i < grades.size(); ++i) {
            result += to_string(grades[i]);
            if (i < grades.size() - 1) {
                result += ", ";
            }
        }
        result += "]";
        return result;
    }

    Student(const Student& other) {
        name = other.name;
        grades = other.grades;
    }

    vector<int>& getGrades() {
        return grades;
    }

    void setGrades(const vector<int>& newGrades) {
        grades = newGrades;
    }
};

int main() {
    vector<int> vasyaGrades = {3, 4, 5};
    Student vasya("Vasya", vasyaGrades);
    
    Student petya = vasya;
    
    petya.getGrades()[0] = 5;
    
    cout << "Vasya: " << vasya.toString() << endl;
    cout << "Petya: " << petya.toString() << endl;

    Student andrey = Student(vasya);
    
    vasya.getGrades()[1] = 10;
    
    cout << "\nAfter changing Vasya's grade:" << endl;
    cout << "Vasya: " << vasya.toString() << endl;
    cout << "Andrey: " << andrey.toString() << endl;

    return 0;
}
