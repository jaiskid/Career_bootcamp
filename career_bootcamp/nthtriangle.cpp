#include<iostream>
using namespace std;
void inverted(int n){
	if(n<1)
	return ;
	cout<<"*	";
	inverted(n-1);
}
void inverted2(int n){
	if(n<1)
	return;
	inverted(n);
	cout<<endl;
	inverted2(n-1);
}
int main() {
	int n;
	cin>>n;
	inverted2(n);
}