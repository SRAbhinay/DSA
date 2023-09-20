#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef long long ll;
const ll base = 257; // base for polynomial rolling hash

std::vector<int> rabin_karp_multi_patterns(const std::string& text, const std::vector<std::string>& patterns) {
    int m = patterns[0].length();
    std::vector<ll> pattern_hashes;
    for (const auto& pattern : patterns) {
        ll hash_val = 0;
        for (char c : pattern) {
            hash_val = (hash_val * base + c) % LLONG_MAX;
        }
        pattern_hashes.push_back(hash_val);
    }

    std::vector<int> matches;
    ll hash_val = 0;
    ll power = 1;
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        hash_val = (hash_val * base + c) % LLONG_MAX;
        if (i >= m) {
            char c_removed = text[i - m];
            ll power_removed = power * c_removed % LLONG_MAX;
            hash_val = (hash_val - power_removed + LLONG_MAX) % LLONG_MAX;
            power = (power * base) % LLONG_MAX;
        }
        if (i >= m - 1) {
            for (int j = 0; j < pattern_hashes.size(); j++) {
                if (hash_val == pattern_hashes[j] && text.substr(i - m + 1, m) == patterns[j]) {
                    matches.push_back(i - m + 1);
                }
            }
        }
    }
    return matches;
}

int main() {
    std::string text = "aabcdeabcfabc";
    std::vector<std::string> patterns = {"abc", "fabc"};
    std::vector<int> matches = rabin_karp_multi_patterns(text, patterns);
    std::cout << "Matches found at positions: ";
    for (auto match : matches) {
        std::cout << match << " ";
    }
    std::cout << std::endl;
    return 0;
}
