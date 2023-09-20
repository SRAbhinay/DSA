#include <iostream>
#include <cstring>
#include <algorithm>
#include<math.h>
using namespace std;

const int MAX = 100;
const int INF = 1e9;
int dp[MAX][MAX];
int p[MAX];
int n;

int MatrixChainOrder(int i, int j)
{
    if (dp[i][j] != INF)
        return dp[i][j];
    if (i == j)
        return 0;
    for (int k = i; k < j; k++)
    {
        int q = MatrixChainOrder(i, k) + MatrixChainOrder(k + 1, j) + p[i - 1] * p[k] * p[j];
        dp[i][j] = min(dp[i][j], q);
    }
    return dp[i][j];
}

int main()
{
    cin >> n;
    
    int a[n];
    for(int i=0;i<n;i++){
    p[i] = rand()%200;
    cout<<p[i]<<endl;
    }
    clock_t start=clock();
    memset(dp, 0x3f, sizeof dp);
    cout << MatrixChainOrder(1, n - 1) << endl;
    clock_t end=clock();
    double tt=(double(end-start)/CLOCKS_PER_SEC)*pow(10,6);
    cout<<"\nTime taken: "<<tt<<endl;
    return 0;
}

