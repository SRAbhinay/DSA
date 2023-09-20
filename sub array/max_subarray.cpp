#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k;
    //n: size of input array
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    int sum,msum=0;
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=i;j<n;j++)
        {
            sum+=a[j];
            msum=max(msum,sum);
        }
    }
    cout<<msum<<endl;
  return 0;
}
