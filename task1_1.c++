#include <iostream>
#include <string>
using namespace std;

class Point {
private:
    int x, y; // Coordinates of the point

public:
    // Constructor to initialize the point with coordinates
    Point(int xCoord, int yCoord) {
        x = xCoord;
        y = yCoord;
    }

    // Method to return the string representation of the point
    string toString() const {
        return "{" + to_string(x) + ";" + to_string(y) + "}";
    }
};

int main() {
    Point point1(2, 3);
    Point point2(5, -1);
    Point point3(-4, 7);

    cout << "Point 1: " << point1.toString() << endl;
    cout << "Point 2: " << point2.toString() << endl;
    cout << "Point 3: " << point3.toString() << endl;

    return 0;
}
