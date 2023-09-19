#include <iostream>
using namespace std;

int main() {
    int arr[5] = {5, 1, 8, 3, 7};
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    
    for (int i = 0; i < 5; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    
    cout << "Second largest element: " << secondLargest << endl;
    
    return 0;
}
