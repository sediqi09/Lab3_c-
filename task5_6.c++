#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
#include <sstream>

class StudentWithHonors {
    std::string name;
    std::vector<int> grades;
public:
    StudentWithHonors(const std::string& name, const std::vector<int>& grades = {}) : name(name), grades(grades) {}

    // Calculate the average grade
    double averageGrade() const {
        if (grades.empty()) return 0.0;
        double sum = std::accumulate(grades.begin(), grades.end(), 0);
        return sum / grades.size();
    }

    // Determine if the student is an honor student
    bool isHonorStudent() const {
        if (grades.empty()) return false;
        for (int grade : grades) {
            if (grade < 5) return false;  // all grades must be 5 for honors
        }
        return true;
    }

    // Display student details with average grade (formatted to 2 decimal places) and honors status
    std::string toString() const {
        std::ostringstream os;
        os << std::fixed << std::setprecision(2) << averageGrade();
        return name + " | Average score: " + os.str() + 
               " | Excellent: " + (isHonorStudent() ? "Yes" : "No");
    }
};

int main() {
    // Creating students as per requirements
    StudentWithHonors vasya("Vasya", {3, 4, 5, 4});
    StudentWithHonors petya("Petya", {5, 5, 5, 5});
    
    // Displaying their details
    std::cout << "Students:\n" << vasya.toString() << "\n" << petya.toString() << "\n";
    return 0;
}
