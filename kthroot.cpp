#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	
	while(t--){
	long long int n,k;
	cin>>n;

	cin>>k;
	if(k==1){
	cout<<n<<endl;
	continue;
	}
	long long int l=1,r=1000000,mid;
	while(l<r){
	mid=l+r+1>>1;
	bool flag=1;
	long long int temp=1;
	for(int i=1;i<=k;i++){
	temp*=mid;
	if(temp>n){
	flag=0;
	break;
			}
	}
	if(flag){
	l=mid;
	}
	else{
	r=mid-1;
	}
	}
	cout<<r<<endl;
	}
	return 0;
}