#include <iostream>
#include <vector>
#include <algorithm>
#include<ctime>

using namespace std;

struct Activity {
    int start, finish;
};

bool cmp(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    cin >> n;

    vector<Activity> activities(n);
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].finish;
    }
    clock_t tStart = clock();

    sort(activities.begin(), activities.end(), cmp);

    vector<int> dp(n);
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (activities[j].finish <= activities[i].start) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxActivities = *max_element(dp.begin(), dp.end());

    cout << "Maximum number of activities that can be scheduled is " << maxActivities << endl;
    double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
        cout<<"Time taken is "<<time1<<endl;
    return 0;
}

