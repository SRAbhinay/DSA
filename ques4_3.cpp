#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> MINIMUM_VALUE_MAXIMAL_SUBARRAY(vector<int> A) {
    int minSum = INT_MAX;
    int start = 0;
    int end = 0;
    int maxLength = 0;

    for (int i = 0; i < A.size(); i++) {
        int sum = 0;
        int j = i;
        while (j < A.size()) {
            sum = sum + A[j];
            if (sum < minSum || (sum == minSum && j - i + 1 > maxLength)) {
                minSum = sum;
                start = i;
                end = j;
                maxLength = j - i + 1;
            }
            j = j + 1;
        }
    }

    vector<int> result(A.begin() + start, A.begin() + end + 1);
    return result;
}

int main() {
    vector<int> A;
A.push_back(1);
A.push_back(2);
A.push_back(3);
A.push_back(4);
A.push_back(5);

    vector<int> result = MINIMUM_VALUE_MAXIMAL_SUBARRAY(A);
    cout << "The minimum value maximal subarray is: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}
