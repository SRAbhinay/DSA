#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    // Traverse array
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    
    // Insert an element
    arr[5] = 6;
    
    // Delete an element
    for (int i = 2; i < 5; i++) {
        arr[i] = arr[i+1];
    }
    
    // Search for an element
    int target = 4;
    for (int i = 0; i < 5; i++) {
        if (arr[i] == target) {
            cout << "Found at index " << i << endl;
            break;
        }
    }
    
    return 0;
}