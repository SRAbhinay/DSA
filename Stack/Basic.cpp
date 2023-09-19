#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    
    // Push elements onto the stack
    s.push(1);
    s.push(2);
    s.push(3);
    
    // Pop elements from the stack
    s.pop();
    
    // Check if the stack is empty
    if (s.empty()) {
        cout << "Stack is empty." << endl;
    }
    
    // Get the top element of the stack
    int topElement = s.top();
    
    cout << "Top element: " << topElement << endl;
    
    return 0;
}
