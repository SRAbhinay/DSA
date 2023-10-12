#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &A, int start, int mid, int end)
{
	int nL = mid - start + 1;
	int nR = end - mid;
	vector<int> left, right;
	for ( int i = 1; i <= nL; i++ )
		left.push_back( A[start + i - 1] );
	left.push_back(INT_MAX);
	for ( int i = 1; i <= nR; i++ )
		right.push_back( A[mid + i] );
	right.push_back(INT_MAX);
	int i = 0;
	int j = 0;
	for ( int k = start; k <= end; k++ )
	{
		if ( left[i] <= right[j] )
		{
			A[k] = left[i];
			i++;
		}
		else
		{
			A[k] = right[j];
			j++;
		}
	}
}
void mergeSort(vector<int> &A, int start, int end)
{
	if ( start < end ) {
		int mid = ( start + end - 1 ) / 2;
		mergeSort( A, start, mid );
		mergeSort( A, mid + 1, end );
		merge( A, start, mid, end );
	}
}

int main()
{
	int n;
	vector<int> A;
	cin >> n;
	for( int i = 0; i < n; i++ )
	{
		int ele;
		cin >> ele;
		A.push_back(ele);
	}

	clock_t tStart = clock();
	mergeSort(A, 0, n - 1);
	double t=(double)(clock() - tStart) / CLOCKS_PER_SEC;
	cout << "Time taken (in seconds) : " << t << endl;
	
	for( auto i = 0; i < n; i++ )
		//cout << A[i] << ", ";
        
	return 0;
}
