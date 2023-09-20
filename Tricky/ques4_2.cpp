#include <iostream>
#include <algorithm>
#include <vector>
#include<ctime>

using namespace std;

void backtrack(vector<string>& result, string& curr, string& unused) {
    if (unused.empty()) {
        result.push_back(curr);
        return;
    }
    for (int i = 0; i < unused.size(); i++) {
        curr.push_back(unused[i]);
        string new_unused = unused;
        new_unused.erase(i, 1);
        backtrack(result, curr, new_unused);
        curr.pop_back();
    }
}

vector<string> permutations(string s) {
    vector<string> result;
    string curr = "";
    sort(s.begin(), s.end());
    backtrack(result, curr, s);
    return result;
}

int main() {
    string s;
    cin >> s;
    clock_t tStart = clock();
    vector<string> result = permutations(s);
    double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
        cout<<"Time taken is "<<time1<<endl;
    return 0;
}

