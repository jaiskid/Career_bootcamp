#include<iostream>
using namespace std;
bool isInverse(){
	int n;
	cin>>n;
	int a[n];
	int b[n];
	int i;
	for(int i=0;i<n;i++){
	cin>>a[i];
	}
	for(i=0;i<n;i++){
	b[a[i]]=i;
	}
	for(i=0;i<n;i++){
	if(a[i]!=b[i])
	break;
	}
	if(i==n){
	return true;
	}
	else
	return false;
}
int main(){
	(isInverse())?cout<<"true":cout<<"false";
}