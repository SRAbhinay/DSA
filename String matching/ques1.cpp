#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> generateAllSubsequences(vector<int> sequence) {
    int n = sequence.size();
    vector<vector<int>> subsequences;
    for (int length = 1; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            vector<int> subsequence;
            for (int j = i; j < i + length; j++) {
                subsequence.push_back(sequence[j]);
            }
            subsequences.push_back(subsequence);
        }
    }
    return subsequences;
}

vector<int> maxLengthCommonSubsequence(vector<int> X, vector<int> Y) {
    vector<vector<int>> X_subsequences = generateAllSubsequences(X);
    vector<vector<int>> Y_subsequences = generateAllSubsequences(Y);
    vector<vector<int>> common_subsequences;
    for (auto x_subsequence : X_subsequences) {
        for (auto y_subsequence : Y_subsequences) {
            if (includes(y_subsequence.begin(), y_subsequence.end(), x_subsequence.begin(), x_subsequence.end())) {
                common_subsequences.push_back(x_subsequence);
            }
        }
    }
    int max_length = 0;
    vector<int> max_subsequence;
    for (auto subsequence : common_subsequences) {
        if (subsequence.size() > max_length) {
            max_length = subsequence.size();
            max_subsequence = subsequence;
        }
    }
    return max_subsequence;
}

int main() {
    vector<int> X = {1, 2, 3, 4, 1};
    vector<int> Y = {3, 4, 1, 2, 1};
    vector<int> max_subsequence = maxLengthCommonSubsequence(X, Y);
    cout << "The maximum-length common subsequence of X and Y is: ";
    for (auto x : max_subsequence) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

