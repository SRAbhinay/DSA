#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> findValidShifts(string T, string P) {
    vector<int> validShifts;

    int n = T.length();
    int m = P.length();

    for (int i = 0; i <= n - m; i++) {
        if (T[i] == P[0] || P[0] == '.') {
            bool match = true;
            for (int j = 1; j < m; j++) {
                if (P[j] != '.' && T[i+j] != P[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                validShifts.push_back(i);
            }
        }
    }

    return validShifts;
}

int main() {
    string T = "abbacbbabacaba";
    string P = "ab.ba.c";

    vector<int> validShifts = findValidShifts(T, P);

    cout << "Valid shifts: ";
    if (validShifts.empty()) {
        cout << "none";
    } else {
        for (int shift : validShifts) {
            cout << shift << " ";
        }
    }
    cout << endl;

    return 0;
}
