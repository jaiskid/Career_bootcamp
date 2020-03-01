#include<iostream>
using namespace std;
int count(int *arr,int n,int m){
	int counter=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]<0)
			counter++;
		}
	}
return count;
}
int main()
{
	int n,m;
	cin>>n>>m;
	int arr[10005][10005];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		cin>>arr[i][j];
		}
}
	cout<<count(arr,n,m);
}