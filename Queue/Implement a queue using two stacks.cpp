#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> inputStack;
    stack<int> outputStack;

public:
    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        int frontElement = outputStack.top();
        outputStack.pop();
        return frontElement;
    }

    int peek() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);

    cout << "Front element: " << q.peek() << endl; // Output: 1
    q.pop();
    cout << "Front element: " << q.peek() << endl; // Output: 2

    return 0;
}
