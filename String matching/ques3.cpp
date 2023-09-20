#include <iostream>
#include <string>
#include <vector>

using namespace std;

int LCS(const string &X, const string &Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> c(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++) {
        c[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        c[0][j] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = max(c[i][j - 1], c[i - 1][j]);
            }
        }
    }
    return c[m][n];
}

int main() {
    string X, Y;
    cout << "Enter the first sequence: ";
    cin >> X;
    cout << "Enter the second sequence: ";
    cin >> Y;
    cout << "The length of the LCS is: " << LCS(X, Y) << endl;
    return 0;
}

