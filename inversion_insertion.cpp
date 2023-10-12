#include <iostream>
#include <vector>

using namespace std;

int countInversions(vector<int> &A) {
    int count = 0;
    for (int i = 1; i < A.size(); i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            count++;
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
    return count;
}

int main() {
    vector<int> elements;
    int key,i,j,n,ele;
    cout<<"Enter number of elements";
    cin>>n;
    for(i=0;i<n;i++)
{
        cin>>ele;
    elements.push_back(ele); //best case
    //selements.push_back(ele-i+1); //worst case
    //elements.push_back(rand()%n); //average case
}
    clock_t tStart = clock();
    cout << "Number of inversions: " << countInversions(elements) << endl;
    double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
        cout<<"Time taken is "<<time1<<endl;
    return 0;
}
