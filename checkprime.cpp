#include<iostream>
using namespace std;
bool isPrime(int n){
	for(int i=2;i<n;i++){
	if(j%i==0){
	return false;
	}
	}
	return true;
}
int main(){
	int n;
	cin>>n;
	(isPrime(n))?cout<<"true\n":cout<<"\false\n";
}