#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LIS(vector<int>& sequence) {
    int n = sequence.size();
    vector<int> LIS_lengths(n, 1);  // Initialize LIS_lengths to 1 for all indi
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (sequence[j] < sequence[i]) {
                LIS_lengths[i] = max(LIS_lengths[i], LIS_lengths[j] + 1);
            }
        }
    }
    return *max_element(LIS_lengths.begin(), LIS_lengths.end());  // Find the maximum LIS value
}

// Example usage
int main() {
    vector<int> sequence = {3, 1, 5, 2, 6, 4, 9};
    cout << LIS(sequence) << endl;  // Output: 4
    return 0;
}

