#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    
    // Enqueue elements
    q.push(1);
    q.push(2);
    
    // Dequeue elements
    q.pop();
    
    // Check if the queue is empty
    if (q.empty()) {
        cout << "Queue is empty." << endl;
    }
    
    // Get the front element
    int frontElement = q.front();
    
    cout << "Front element: " << frontElement << endl;
    
    return 0;
}
