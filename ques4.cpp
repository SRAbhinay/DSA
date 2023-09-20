
#include <iostream>
#include <cmath>
#include<ctime>

using namespace std;
int count_solutions(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int j = (int)std::sqrt(n - i * i);
        count += j;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    clock_t tStart = clock();
    cout << count_solutions(n) << endl;
    double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
        cout<<"Time taken is "<<time1<<endl;
   

    return 0;
}

