#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool twoDStringMatch(vector<vector<char>>& T, vector<vector<char>>& P) {
    int n = T.size();
    int m = T[0].size();
    int p = P.size();
    int q = P[0].size();
    
    for (int i = 0; i <= n-p; i++) {
        for (int j = 0; j <= m-q; j++) {
            bool match = true;
            for (int x = 0; x < p; x++) {
                for (int y = 0; y < q; y++) {
                    if (T[i+x][j+y] != P[x][y]) {
                        match = false;
                        break;
                    }
                }
                if (!match) {
                    break;
                }
            }
            if (match) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> T = {
        {'a', 'b', 'c', 'd'},
        {'e', 'f', 'g', 'h'},
        {'i', 'j', 'k', 'l'},
        {'m', 'n', 'o', 'p'}
    };
    
    vector<vector<char>> P = {
        {'f', 'g'},
        {'j', 'k'}
    };
    
    if (twoDStringMatch(T, P)) {
        cout << "Pattern P found in T!" << endl;
    } else {
        cout << "Pattern P not found in T." << endl;
    }
    
    return 0;
}

