#include<iostream>
#define ll long long int 
using namespace std;
ll moditerative(ll a,ll b,ll c){
	ll ans=1;
	while(b!=0){
	if(b&1){
	ans=((ans%c)*(a%c))%c;
	}
	a=((a%c)*(a%c))%c;
	b>>=1;
	}
	return ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
	ll a,n,p;
	cin>>a>>n>>p;
	ll ans=0;
	for(int i=2;i<=n;i++){
	 ans=moditerative(a,i,p);
	} 
	cout<<ans<<endl;
	}
	
}