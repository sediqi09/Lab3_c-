#include <iostream>
#include <string>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int xCoord, int yCoord) {
        x = xCoord;
        y = yCoord;
    }

    string toString() const {
        return "{" + to_string(x) + ";" + to_string(y) + "}";
    }

    int getX() const { return x; }
    int getY() const { return y; }
};

class Line {
private:
    Point start, end;

public:
    // Constructor to initialize the start and end points
    Line(Point startPoint, Point endPoint) : start(startPoint), end(endPoint) {}

    // Method to return the string representation of the line
    string toString() const {
        return "Line from " + start.toString() + " to " + end.toString();
    }

    Point getStart() const { return start; }
    Point getEnd() const { return end; }

    // Mutator functions to change the start and end points
    void setStart(Point newStart) { start = newStart; }
    void setEnd(Point newEnd) { end = newEnd; }
};

int main() {
    Point p1(1, 3);
    Point p2(23, 8);
    Line line1(p1, p2);

    Point p3(5, 10);
    Point p4(25, 10);
    Line line2(p3, p4);

    Line line3(line1.getStart(), line2.getEnd());

    cout << line1.toString() << endl;
    cout << line2.toString() << endl;
    cout << line3.toString() << endl;

    line1.setStart(Point(2, 5)); // Change start of Line 1
    line1.setEnd(Point(20, 15)); // Change end of Line 1
    line2.setStart(Point(10, 10)); // Change start of Line 2
    line2.setEnd(Point(30, 10));   // Change end of Line 2

    line3.setStart(line1.getStart()); // Line 3 starts where Line 1 starts
    line3.setEnd(line2.getEnd());     // Line 3 ends where Line 2 ends

    cout << "\nAfter modifying Line 1 and Line 2:" << endl;
    cout << line1.toString() << endl;
    cout << line2.toString() << endl;
    cout << line3.toString() << endl;

    line1.setStart(Point(2, 5));  // Keep Line 3's position unchanged
    line3.setStart(line1.getStart());

    // Display final lines after the last change
    cout << "\nAfter changing Line 1 while keeping Line 3 unchanged:" << endl;
    cout << line1.toString() << endl;
    cout << line2.toString() << endl;
    cout << line3.toString() << endl;

    return 0;
}
