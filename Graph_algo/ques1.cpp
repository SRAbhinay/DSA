#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

void generatePointsOnLineSegment(Point p1, Point p2, int n) {
    // Calculate distance between p1 and p2
    double dist = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));

    // Calculate x and y distances between each point
    double dx = (p2.x - p1.x) / (n-1);
    double dy = (p2.y - p1.y) / (n-1);

    // Generate n points on the line segment
    for (int i = 0; i < n; i++) {
        double x = p1.x + i*dx;
        double y = p1.y + i*dy;
        cout << "Point " << i+1 << ": (" << x << ", " << y << ")" << endl;
    }
}

int main() {
    Point p1 = {0, 0}; // Endpoint 1
    Point p2 = {10, 10}; // Endpoint 2
    int n = 5; // Number of points to generate

    generatePointsOnLineSegment(p1, p2, n);

    return 0;
}

