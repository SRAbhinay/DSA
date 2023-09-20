#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 100;
int m[MAX][MAX];
int s[MAX][MAX];
vector<string> sols;

int MatrixChainOrder(const vector<int> &p) {
    int n = p.size() - 1;
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[1][n];
}

int main() {
    vector<int> p;
p.push_back(30);
p.push_back(35);
p.push_back(15);
p.push_back(5);
p.push_back(10);
p.push_back(20);
p.push_back(25);

    cout << "Minimum number of multiplications is " << MatrixChainOrder(p) << endl;
   
    return 0;
}

