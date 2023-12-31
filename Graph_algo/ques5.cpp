#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

double calculateSlope(Point p1, Point p2) {
    if (p1.x == p2.x) {
        return INFINITY;
    }
    return (p2.y - p1.y) / (p2.x - p1.x);
}

bool arePerpendicular(Point p1, Point p2, Point p3, Point 
p4) {
    double m1 = calculateSlope(p1, p2);
    double m2 = calculateSlope(p3, p4);
    
    if (m1 == INFINITY) {
        return m2 == 0;
    }
    else if (m2 == INFINITY) {
        return m1 == 0;
    }
    else {
        return m1 * m2 == -1;
    }
}

int main() {
    Point p1 = {1, 2};
    Point p2 = {3, 4};
    Point p3 = {5, 6};
    Point p4 = {7, 8};
    
    if (arePerpendicular(p1, p2, p3, p4)) {
        cout << "Line segments are perpendicular." << 
endl;
    }
    else {
        cout << "Line segments are not perpendicular." << 
endl;
    }
    
    return 0;
}

