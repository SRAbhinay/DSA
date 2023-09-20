#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<vector<int>>& result, vector<int>& curr, vector<int>& S, int k, int start) {
    int sum = 0;
    for (int x : curr) {
        sum += x;
    }
    if (sum == k) {
        result.push_back(curr);
        return;
    }
    for (int i = start; i < S.size(); i++) {
        if (sum + S[i] <= k) {
            curr.push_back(S[i]);
            backtrack(result, curr, S, k, i+1);
            curr.pop_back();
        }
    }
}

vector<vector<int>> subsetSum(vector<int>& S, int k) {
    vector<vector<int>> result;
    vector<int> curr;
    backtrack(result, curr, S, k, 0);
    return result;
}

int main() {
    vector<int> S = {1, 2, 3, 4, 5};
    int k = 6;
    vector<vector<int>> result = subsetSum(S, k);
    for (vector<int> subset : result) {
        for (int x : subset) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}

