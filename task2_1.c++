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
    Line(Point startPoint, Point endPoint) : start(startPoint), end(endPoint) {}

    string toString() const {
        return "Line from " + start.toString() + " to " + end.toString();
    }

    Point getStart() const { return start; }
    Point getEnd() const { return end; }

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

    line1.setStart(Point(2, 5));
    line1.setEnd(Point(20, 15));
    line2.setStart(Point(10, 10));
    line2.setEnd(Point(30, 10));

    line3.setStart(line1.getStart());
    line3.setEnd(line2.getEnd());

    cout << "\nAfter modifying Line 1 and Line 2:" << endl;
    cout << line1.toString() << endl;
    cout << line2.toString() << endl;
    cout << line3.toString() << endl;

    line1.setStart(Point(2, 5));
    line3.setStart(line1.getStart());

    cout << "\nAfter changing Line 1 while keeping Line 3 unchanged:" << endl;
    cout << line1.toString() << endl;
    cout << line2.toString() << endl;
    cout << line3.toString() << endl;

    return 0;
}
