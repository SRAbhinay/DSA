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
    cout << "Enter the number of activities: ";
    cin >> n;
    
    vector<Activity> activities(n);
    cout << "Enter the start and finish time of each activity:\n";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].finish;
    }
    clock_t tStart = clock();
    sort(activities.begin(), activities.end(), cmp);
    
    vector<int> assignedHalls;
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < assignedHalls.size() && activities[i].start >= assignedHalls[j]) {
            j++;
        }
        if (j == assignedHalls.size()) {
            assignedHalls.push_back(activities[i].finish);
        } else {
            assignedHalls[j] = activities[i].finish;
        }
        cout << "Activity " << i+1 << " assigned to hall " << j+1 << endl;
    }
    
    cout << "Minimum number of halls required: " << assignedHalls.size() << endl;
    double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
        cout<<"Time taken is "<<time1<<endl;
    return 0;
}

