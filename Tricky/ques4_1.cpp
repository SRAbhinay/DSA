#include <iostream>
#include <algorithm>
#include <vector>
#include<ctime>

using namespace std;

vector<string> permutations(string s) {
    vector<string> result;
    sort(s.begin(), s.end());
    do {
        result.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
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

