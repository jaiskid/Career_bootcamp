#include<iostream>
using namespace std;
bool issorted(int *arr,int n){
	if(n==1)
	return true;
	if(arr[0]<=arr[1]&&issorted(arr+1,n-1))
	return true;

	return false;
}
int main() {
	int n;
	cin>>n;
	int arr[100005];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	(issorted(arr,n))?cout<<"true\n":cout<<"false\n";
}