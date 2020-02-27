#include<iostream>
#include <bitset>
using namespace std;
int count_(int n1,int n2){
int ans=0;
	for(int i=n1;i<=n2;i++){
	bitset<1000> b1(i);
	ans+=b1.count();
	}
	return ans;
}
int main(){
	int t;
	cin>>t;

	while(t--){
	int n1, n2;
	cin>>n1>>n2;
	cout<<count_(n1,n2)<<endl;

	}
}