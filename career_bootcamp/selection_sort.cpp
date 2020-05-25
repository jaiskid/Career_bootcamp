#include<iostream>
using namespace std;
void selection_sort(int *arr,int n){
	for(int i=0;i<n;i++){
		int minindex=i;
		for(int j=i;j<n;j++){
			if(arr[j]<arr[minindex]){
				minindex=j;
			}
		}
		swap(arr[i],arr[minindex]);
	}
}
int main() {
	int n;
	cin>>n;
	int arr[100005];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	selection_sort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}