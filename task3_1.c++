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

    // Method to return the string representation of the student
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

    // Copy constructor for deep copy
    Student(const Student& other) {
        name = other.name;
        grades = other.grades;
    }

    // Accessor to get grades (used for modification)
    vector<int>& getGrades() {
        return grades;
    }

    // Mutator to set the grades (if needed)
    void setGrades(const vector<int>& newGrades) {
        grades = newGrades;
    }
};

int main() {
    vector<int> vasyaGrades = {3, 4, 5};
    Student vasya("Vasya", vasyaGrades);
    
    Student petya = vasya;  // Shallow copy for now (we will modify this below)
    
    // Replace Petya's first grade with 5
    petya.getGrades()[0] = 5;
    
    // Display Vasya and Petya's string representations
    cout << "Vasya: " << vasya.toString() << endl;
    cout << "Petya: " << petya.toString() << endl;

    Student andrey = Student(vasya);  // Deep copy using the copy constructor
    
    vasya.getGrades()[1] = 10;  // Change Vasya's second grade to 10
    
    // Display Vasya and Andrey's string representations
    cout << "\nAfter changing Vasya's grade:" << endl;
    cout << "Vasya: " << vasya.toString() << endl;
    cout << "Andrey: " << andrey.toString() << endl;

    return 0;
}
