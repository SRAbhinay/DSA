#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start, finish;
};

bool activityCompare(const Activity& a, const Activity& b) {
    return a.finish < b.finish;
}

vector<Activity> selectActivities(vector<Activity> activities) {
    // sort the activities by finish time
    sort(activities.begin(), activities.end(), activityCompare);

    vector<Activity> selected;
    selected.push_back(activities[0]);

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= selected.back().finish) {
            selected.push_back(activities[i]);
        }
    }

    return selected;
}

int main() {
    vector<Activity> activities = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 9}, 
{5, 9},
                                   {6, 10}, {8, 11}, {8, 12}, {2, 14}, 
{12, 16}};
    vector<Activity> selected = selectActivities(activities);

    cout << "Selected activities: ";
    for (int i = 0; i < selected.size(); i++) {
        cout << "(" << selected[i].start << ", " << selected[i].finish << 
")";
        if (i != selected.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}

