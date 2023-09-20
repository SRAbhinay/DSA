#include <iostream>

using namespace std;

struct Point {
    double x;
    double y;
};

bool isClockwise(Point p1, Point p2, Point q) {
    // Calculate vectors P1P2 and P1q
    double vectorP1P2_x = p2.x - p1.x;
    double vectorP1P2_y = p2.y - p1.y;
    double vectorP1q_x = q.x - p1.x;
    double vectorP1q_y = q.y - p1.y;
    
    // Calculate cross product of vectors
    double crossProduct = vectorP1P2_x * vectorP1q_y - vectorP1P2_y * 
vectorP1q_x;
    
    // Check the sign of the cross product
    if (crossProduct < 0) {
        return true; // q is in the clockwise direction from P1P2
    }
    else {
        return false; // q is not in the clockwise direction from P1P2
    }
}

int main() {
    Point p1 = {0, 0}; // Endpoint 1
    Point p2 = {10, 10}; // Endpoint 2
    Point q1 = {5, 0}; // Point in the clockwise direction
    Point q2 = {5, 5}; // Point collinear with P1P2
    Point q3 = {0, 5}; // Point in the counter-clockwise direction
    
    if (isClockwise(p1, p2, q1)) {
        cout << "q1 is in the clockwise direction from P1P2" << endl;
    }
    else {
        cout << "q1 is not in the clockwise direction from P1P2" << endl;
    }
    
    if (isClockwise(p1, p2, q2)) {
        cout << "q2 is in the clockwise direction from P1P2" << endl;
    }
    else {
        cout << "q2 is not in the clockwise direction from P1P2" << endl;
    }
    
    if (isClockwise(p1, p2, q3)) {
        cout << "q3 is in the clockwise direction from P1P2" << endl;
    }
    else {
        cout << "q3 is not in the clockwise direction from P1P2" << endl;
    }
    
    return 0;
}

