#include <iostream>
#include <vector>
using namespace std;
vector<int> memo;
int fiba(int n) {
    if (memo[n] != -1) {
        return memo[n];
    }
    if (n == 1) {
        memo[n] = 0;
    }
    else if (n == 2) {
        memo[n] = 1;
    }
    else if (n == 3) {
        memo[n] = 2;
    }
    else {
        memo[n] = fiba(n-1) + fiba(n-2) + fiba(n-3);
    }
    return memo[n];
}
int main() {
    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;
    memo = vector<int>(n+1, -1);
    cout << "fiba(" << n << ") = " << fiba(n) << endl;
    return 0;
}

