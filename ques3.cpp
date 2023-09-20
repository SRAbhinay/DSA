#include <iostream>
#include <vector>
#include <algorithm> // for sort() and lower_bound()

using namespace std;

struct Activity {
    int start, finish;
};

bool cmp(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n; // number of activities
    cin >> n;

    vector<Activity> activities(n);
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].finish;
    }

    sort(activities.begin(), activities.end(), cmp);

    vector<int> assignedHalls;
    for (int i = 0; i < n; i++) {
        int j = lower_bound(assignedHalls.begin(), assignedHalls.end(), activities[i].start) - assignedHalls.begin();
        if (j < assignedHalls.size()) {
            assignedHalls[j] = activities[i].finish;
        } else {
            assignedHalls.push_back(activities[i].finish);
        }
        cout << "Activity " << i+1 << " assigned to hall " << j+1 << endl;
    }

    return 0;
}

