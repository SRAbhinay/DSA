#include <climits>
#include <iostream>
#include<math.h>
using namespace std;
 
void maxSubArraySum(int a[], int size)
{
int max_so_far = INT_MIN, max_ending_here = 0,
start = 0, end = 0, s = 0;
 
for (int i = 0; i < size; i++) {
max_ending_here += a[i];
 
if (max_so_far < max_ending_here) {
max_so_far = max_ending_here;
start = s;
end = i;
}
 
if (max_ending_here < 0) {
max_ending_here = 0;
s = i + 1;
}
}
cout << "Max contiguous sum is " << max_so_far
<< endl;
cout << "Starting:  " << start << endl
<< "Ending:  " << end << endl;
}
int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
a[i] = rand()%200;
cout<<a[i]<<endl;
}
clock_t start=clock();
maxSubArraySum(a, n);
clock_t end=clock(); 
double tt=(double(end-start)/CLOCKS_PER_SEC)*pow(10,6);   
cout<<"\nTime taken: "<<tt<<endl;
return 0;
}
