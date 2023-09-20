#include<iostream>
using namespace std;
int maxRevenue(int n, int prices[], int revenue[]) {
    if (revenue[n] >= 0) {
        return revenue[n];
    }
    int max_val;
    if (n == 0) {
        max_val = 0;
    }
    else {
        max_val = INT_MIN;
        for (int i = 1; i <= n; i++) {
            max_val = max(max_val, prices[i] + maxRevenue(n - i, prices, revenue));
        }
    }
    revenue[n] = max_val;
    return max_val;
}

int main() {
    int n;
    cout<<"Enter the length of the rod: ";
    cin>>n;
    int prices[n+1];
    cout<<"Enter the prices of the rod of length 1 to "<<n<<": ";
    for (int i = 1; i <= n; i++) {
        cin>>prices[i];
    }
    int revenue[n+1];
    memset(revenue, -1, sizeof(revenue));
    cout<<"The maximum revenue obtainable is: "<<maxRevenue(n, prices, revenue)<<endl;
    return 0;
}

