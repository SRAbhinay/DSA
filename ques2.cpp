#include <algorithm>
#include <iostream>

int find_maximum(int A[], int low, int high) {
    if (low == high) {
        return A[low];
    } else {
        int mid = (low + high) / 2;
        int max_left = find_maximum(A, low, mid);
        int max_right = find_maximum(A, mid + 1, high);
        return std::max(max_left, max_right);
    }
}

int maximum_in_array(int A[], int n) {
    return find_maximum(A, 0, n - 1);
}

int main() {
    int A[] = {1, 2, 453, 4, 5};
    int n = 5;
    int max_element = maximum_in_array(A, n);
    std::cout << "The maximum element is: " << max_element << std::endl;
    return 0;
}
