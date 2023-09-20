#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 505;
int p[N], dp[N][N];

int MCM(int i, int j) {
  if (i == j) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  int ans = INT_MAX;
  for (int k = i; k < j; k++) {
    int q = MCM(i, k) + MCM(k + 1, j) + p[i - 1] * p[k] * p[j];
    ans = min(ans, q);
  }
  return dp[i][j] = ans;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];
  memset(dp, -1, sizeof dp);
  cout << MCM(1, n - 1) << endl;
  return 0;
}

