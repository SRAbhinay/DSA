#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> computePrefix(string s) {
    int n = s.size();
    vector<int> prefix(n);
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = prefix[j-1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        prefix[i] = j;
    }
    return prefix;
}

bool isCyclicRotation(string t, string tprime) {
    if (t.size() != tprime.size()) {
        return false;
    }
    string s = t + t;
    vector<int> prefix = computePrefix(tprime);
    int n = s.size();
    int m = tprime.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != tprime[j]) {
            j = prefix[j-1];
        }
        if (s[i] == tprime[j]) {
            j++;
        }
        if (j == m) {
            return true;
        }
    }
    return false;
}

int main() {
    string t = "car";
    string tprime = "arc";
    if (isCyclicRotation(t, tprime)) {
        cout << t << " is a cyclic rotation of " << tprime << endl;
    } else {
        cout << t << " is not a cyclic rotation of " << tprime << endl;
    }
    return 0;
}

