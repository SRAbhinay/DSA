#include <iostream>
#include <vector>
using namespace std;

vector<int> MAXIMUM_VALUE_MINIMAL_SUBARRAY(vector<int> A) {
    int maxSum = 0;
    int start = 0;
    int end = 0;
    int minLength = A.size();

    for (int i = 0; i < A.size(); i++) {
        int sum = 0;
        int j = i;
        while (j < A.size() && A[j] >= 0) {
            sum = sum + A[j];
            if (sum >= maxSum || (sum == maxSum && j - i + 1 < minLength)) {
                maxSum = sum;
                start = i;
                end = j;
                minLength = j - i + 1;
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
    vector<int> result = MAXIMUM_VALUE_MINIMAL_SUBARRAY(A);
    cout << "The maximum value minimal subarray is: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}
