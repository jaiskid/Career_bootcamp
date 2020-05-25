#include<bits/stdc++.h>
using namespace std;
//a^n!%p
long long int fibo(int n){
	long long int ans=1;
	for(int i=1;i<=n;i++){
	ans*=i;
	}
	return ans;
}
long long int power(long long int a,long long int b){
	if(b==0)
	{
		return 1;

	}
	long long int smallpower=power(a,b/2);
	smallpower*=smallpower;
	if(b&1){
		return a*smallpower;
	}
	else{
		return smallpower;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long int a,n,p;
	cin>>a>>n>>p;
	long long int fib=fibo(n);
	long long int result=power(a,fib)%p;
	cout<<result<<endl;
	}
	
}