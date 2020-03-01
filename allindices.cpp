#include<iostream>
using namespace std;
void allindices(int *arr,int key,int s,int n){
	if(s>n){
		return;
	}
	if(arr[s]==key)
	cout<<s<<" ";
	allindices(arr,key,s+1,n);
}
int main() {
	int n;
	cin>>n;
	int arr[100005];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int key;
	cin>>key;
	allindices(arr,key,0,n);
}
