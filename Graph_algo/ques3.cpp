#include <iostream>
#include <map>
#include <vector>
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

void printCollinearSets(vector<vector<Point>> sets) {
    for (auto set : sets) {
        cout << "Collinear set: ";
        for (auto p : set) {
            cout << "(" << p.x << ", " << p.y << ") ";
        }
        cout << endl;
    }
}

void findCollinearSets(vector<Point> points) {
    map<double, vector<Point>> slopeMap;
    vector<vector<Point>> collinearSets;
    
    for (int i = 0; i < points.size(); i++) {
        Point p = points[i];
        
        for (int j = i + 1; j < points.size(); j++) {
            Point q = points[j];
            
            double slope = calculateSlope(p, q);
            if (slopeMap.find(slope) == slopeMap.end()) {
                slopeMap[slope] = {p, q};
            }
            else {
                slopeMap[slope].push_back(p);
                slopeMap[slope].push_back(q);
            }
        }
    }
    
    for (auto iter : slopeMap) {
        if (iter.second.size() >= 3) {
            collinearSets.push_back(iter.second);
        }
    }
    
    printCollinearSets(collinearSets);
}

int main() {
    vector<Point> points = {{1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {2,3}, 
{1,2}, {3,4}};
    
    findCollinearSets(points);
    
    return 0;
}

