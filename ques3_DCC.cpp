#include <iostream>
#include <vector>

using namespace std;

int countInversions(vector<int> &A, int start, int end) {
    if (start >= end) {
        return 0;
    }

    int mid = (start + end) / 2;
    int count = 0;
    count += countInversions(A, start, mid);
    count += countInversions(A, mid + 1, end);

    int i = start;
    int j = mid + 1;
    vector<int> temp;

    while (i <= mid && j <= end) {
        if (A[i] <= A[j]) {
            temp.push_back(A[i]);
            i++;
        } else {
            count += mid - i + 1;
            temp.push_back(A[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(A[i]);
        i++;
    }

    while (j <= end) {
        temp.push_back(A[j]);
        j++;
    }

    for (int k = start; k <= end; k++) {
        A[k] = temp[k - start];
    }

    return count;
}

int main() {
    vector<int> elements;
    int key,i,j,n,ele;
    //cout<<"Enter number of elements";
    cin>>n;
    for(i=0;i<n;i++)
{
        cin>>ele;
    elements.push_back(ele); //best case
    //selements.push_back(ele-i+1); //worst case
    //elements.push_back(rand()%n); //average case
}
    clock_t tStart = clock();
    cout << "Number of inversions: " << countInversions(elements, 0, (n - 1)) << endl;
    double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
        cout<<"Time taken is "<<time1<<endl;
    return 0;
}

