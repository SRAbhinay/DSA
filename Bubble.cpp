#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

void bubbleSort(int arr[], int n) {
    bool isUnsorted;
    do {
        isUnsorted = false;
        for (int i = 0; i < (n - 1); i++) {
            if (arr[i] > arr[i + 1]) {
                isUnsorted = true;
                for (; i < (n - 1); i++) {
                    if (arr[i] > arr[i + 1]) {
                        std::swap(arr[i], arr[i + 1]);
                    }
                }
            }
        }
    } while (isUnsorted);
}
int main()
{
    int n, ele, i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
{
        cin>>ele;
    arr[i]=ele; //best case
    //selements.push_back(ele-i+1); //worst case
    //elements.push_back(rand()%n); //average case
}
    clock_t tStart = clock();    
    bubbleSort(arr, n);
    double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
        cout<<"Time taken is "<<time1<<endl;
    return 0;
}


