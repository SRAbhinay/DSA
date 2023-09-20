#include <iostream>
using namespace std;
void ssort(int arr[], int n) {
for (int i = 0; i < n-1; i++) {
int mi = i;
for (int j = i+1; j < n; j++) {
if (arr[j] < arr[mi]) {
mi = j;
}
}
swap(arr[i], arr[mi]);
cout<<"Hence "<<arr[i]<< " and "<< arr[mi] << " will be replaced. \n";
}
}
int main() {
int n;
cout << "Enter the number of elements: ";
cin >> n;
int arr[n];
cout << "Enter the elements: ";
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
ssort(arr, n);
cout << "The sorted array is: ";
for (int i = 0; i < n; i++) {
cout << arr[i] << " ";
}
return 0;
}