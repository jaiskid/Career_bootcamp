#include<iostream>
using namespace std;
bool break_digit(int n){
	int sume=0;
	int sumo=0;
	while(n){
		int rem=n%10;
		if(rem%2==0){
			sume+=rem;
		}else{
			sumo+=rem;
		}
		n/=10;
	}
	if(sume%4==0||sumo%3==0){
		return true;
	}
	else{
		return false;
	}
}
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		(break_digit(n))?cout<<"Yes\n":cout<<"No\n";
	}
}