#include <iostream>

int count_solutions(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i * i + j * j < n) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << count_solutions(n) << std::endl;
    return 0;
}

