#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> s;
    stack<int> minStack;

public:
    void push(int x) {
        s.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (s.top() == minStack.top()) {
            minStack.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(2);
    minStack.push(0);
    minStack.push(3);
    minStack.push(0);

    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 0

    minStack.pop();
    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 0

    minStack.pop();
    cout << "Top element: " << minStack.top() << endl; // Output: 0

    return 0;
}
