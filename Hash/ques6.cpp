#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

const int p = 31;
const int m = 1e9 + 9;

void findOccurrences(vector<string>& texts, vector<string>& patterns) {
    int n = texts[0].size();
    int k = patterns.size();
    int j = texts.size();
    unordered_map<int, int> power;

    // Precompute powers of p modulo m
    power[0] = 1;
    for (int i = 1; i <= n; i++) {
        power[i] = (power[i-1] * p) % m;
    }

    // Compute hash values of all patterns
    vector<int> patternHash(k);
    for (int i = 0; i < k; i++) {
        string pattern = patterns[i];
        int patternSize = pattern.size();
        int patternHashValue = 0;
        for (int j = 0; j < patternSize; j++) {
            patternHashValue = (patternHashValue + (pattern[j] - 'a' + 1) * power[j]) % m;
        }
        patternHash[i] = patternHashValue;
    }

    // Compute occurrences of all patterns in all texts
    vector<vector<int>> occurrences(n, vector<int>(j));
    for (int t = 0; t < j; t++) {
        string text = texts[t];
        int textSize = text.size();
        vector<int> textHash(textSize+1);
        textHash[0] = 0;
        for (int i = 0; i < textSize; i++) {
            textHash[i+1] = (textHash[i] + (text[i] - 'a' + 1) * power[i]) % m;
        }
        for (int i = 0; i <= textSize-k; i++) {
            for (int p = 0; p < k; p++) {
                int patternHashValue = patternHash[p];
                int substringHashValue = (textHash[i+k] - textHash[i] + m) % m;
                int powerValue = power[i];
                if (substringHashValue == (patternHashValue * powerValue) % m) {
                    occurrences[i][t]++;
                }
            }
        }
    }

    // Output the occurrences of all patterns in all texts
    for (int t = 0; t < j; t++) {
        cout << "Occurrences in text " << t+1 << ":" << endl;
        for (int i = 0; i <= n-k; i++) {
            cout << "At position " << i+1 << ":";
            for (int p = 0; p < k; p++) {
                cout << " " << occurrences[i][t];
            }
            cout << endl;
        }
    }
}

int main() {
    vector<string> texts = {"abcde", "fghij", "klmno"};
    vector<string> patterns = {"ab", "cd", "ef", "gh", "ij", "kl", "mn", "no"};

    findOccurrences(texts, patterns);

    return 0;
}

