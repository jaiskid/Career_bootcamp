#include<iostream>
using namespace std;
int sumin(int n){
	if(n!=0)
	return n+sumin(n-1);
	else{
		return n;
	}
	
}
int main() {
	int n;
	cin>>n;
	cout<<sumin(n);
}