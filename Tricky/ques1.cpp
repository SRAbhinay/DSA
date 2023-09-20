#include <iostream>
#include <vector>

using namespace std;

vector<int> max_distinct_partition(int n) {
    int max_size = 0;
    vector<int> max_partition;
    
    function<void(vector<int>&, int, int)> backtrack = [&](vector<int>& partition, int remaining_sum, int index) {
        if (remaining_sum == 0) {
            if (partition.size() > max_size) {
                max_size = partition.size();
                max_partition = partition;
            }
            return;
        }
        
        for (int i = 1; i <= remaining_sum; i++) {
            if (find(partition.begin(), partition.end(), i) == partition.end()) {
                partition.push_back(i);
                backtrack(partition, remaining_sum-i, index+1);
                partition.pop_back();
            }
        }
    };
    
    vector<int> partition;
    backtrack(partition, n, 1);
    return max_partition;
}

int main() {
    int n = 6;
    vector<int> max_partition = max_distinct_partition(n);
    cout << "Maximum-size distinct partition of " << n << " is:";
    for (int i : max_partition) {
        cout << " " << i;
    }
    cout << endl;
    return 0;
}

