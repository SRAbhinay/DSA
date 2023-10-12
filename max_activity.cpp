#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Activity {
    int start, finish, value;
};

bool compareActivities(Activity a, Activity b) {
    return a.finish < b.finish;
}

int maxActivityValue(vector<Activity>& activities) {
    int n = activities.size();
    sort(activities.begin(), activities.end(), compareActivities);

    // dp[i] stores the maximum value achievable up to activity i
    vector<int> dp(n);
    dp[0] = activities[0].value;

    for (int i = 1; i < n; i++) {
        // Find the maximum j such that aj is compatible with ai
        int j = i - 1;
        while (j >= 0 && activities[j].finish > activities[i].start) {
            j--;
        }
        
        if (j >= 0) {
            dp[i] = max(dp[i-1], dp[j] + activities[i].value);
        } else {
            dp[i] = max(dp[i-1], activities[i].value);
        }
    }

    return dp[n-1];
}

int main() {
    vector<Activity> activities = {
        {1, 4, 2},
        {3, 5, 4},
        {0, 6, 6},
        {5, 7, 4},
        {3, 8, 8},
        {5, 9, 10},
        {6, 10, 12}
    };
    cout << "Maximum activity value: " << maxActivityValue(activities) << endl;
    return 0;
}

