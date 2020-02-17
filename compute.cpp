#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		ll int n;
	cin>>n;
	if(n%2==0){
	cout<<n/2;
	}
	else{
	cout<<(n+1)/2*(-1);
	}
	}
	
}