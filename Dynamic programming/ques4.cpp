#include<iostream>
using namespace std;

int rodCutting(int length, int prices[]) {
    int dp[length+1]; // dp[i] stores the maximum revenue that can be obtained from a rod of length i

    dp[0] = 0; // Base case: The maximum revenue that can be obtained from a rod of length 0 is 0

    for(int i=1; i<=length; i++) {
        dp[i] = prices[i-1]; // Initialize the maximum revenue to the price of a rod of length i

        // Check if cutting the rod into smaller pieces and selling them separately yields a higher revenue
        for(int j=1; j<i; j++) {
            dp[i] = max(dp[i], dp[j] + dp[i-j]);
        }
    }

    return dp[length];
}

int main() {
    int length, prices[100];

    cout << "Enter the length of the rod: ";
    cin >> length;

    cout << "Enter the prices of the rods of length 1 to " << length << ":" << endl;

    for(int i=0; i<length; i++) {
        cin >> prices[i];
    }

    int maxRevenue = rodCutting(length, prices);

    cout << "The maximum revenue that can be obtained from a rod of length " << length << " is: " << maxRevenue << endl;

    return 0;
}

