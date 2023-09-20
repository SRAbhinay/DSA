#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

int main()
{
    vector<int> avector;
    int key,i,j,n,ele;
    cin>>n;
    for(i=0;i<n;i++)
{
        cin>>ele;
    avector.push_back(ele); //best case
    //elements.push_back(ele-i+1); //worst case
    //avector.push_back(rand()%n); //average case
}
    clock_t tStart = clock();
    for (int fillslot = (avector.size() - 1); fillslot >= 0; fillslot--) {
        int positionOfMax = 0;
        for (int location = 1; location < fillslot + 1; location++) {
            if (avector[location] > avector[positionOfMax]) {
                positionOfMax = location;
            }
        }

        int temp = avector[fillslot];
        avector[fillslot] = avector[positionOfMax];
        avector[positionOfMax] = temp;
    }
double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
    cout<<"Time taken is "<<time1<<endl;
   /*for(i=0;i<n;i++)
    {
        cout<<elements[i]<<" ";
    }*/
}
