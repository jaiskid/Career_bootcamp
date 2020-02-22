#include<bits/stdc++.h>
using namespace std;
void reverse(int arr[100][100],int r,int c){
	for(int i=0;i<r;i++){
		for(int j=0,k=c-1;j<k;j++,k--){
		swap(arr[j][i],arr[k][i]);
		}
	}
}
void transpose(int arr[100][100],int r,int c){
	for(int i=0;i<r;i++){
	for(int j=0;j<c;j++){
	swap(arr[i][j],arr[j][i]);
	}
	}
}
void printMatrix(int arr[100][100],int r,int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
		cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
void rotate(int arr[100][100],int r,int c){
	transpose(arr,r,c);
	reverse(arr,r,c);
}
int main(){
	int r;
	cin>>r;
	int c;
	cin>>c;
	int arr[100][100];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>arr[i][j];
		}
	}
	rotate(arr,r,c);
	printMatrix(arr,r,c);
}