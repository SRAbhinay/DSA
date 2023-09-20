#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1005;

int m, n;
int dp[N][N];
string X, Y;

int LCS_length(int i, int j) {
    if (i == 0 || j == 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (X[i - 1] == Y[j - 1]) dp[i][j] = LCS_length(i - 1, j - 1) + 1;
    else dp[i][j] = max(LCS_length(i, j - 1), LCS_length(i - 1, j));
    return dp[i][j];
}

void maximum_length_common_subsequence() {
    memset(dp, -1, sizeof dp);
    int LCS_length_value = LCS_length(m, n);
    cout << "LCS Length Table:" << endl;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Maximum length of common subsequence: " << LCS_length_value << endl;
}

int main() {
    cin >> X >> Y;
    m = X.length();
    n = Y.length();
    maximum_length_common_subsequence();
    return 0;
}

