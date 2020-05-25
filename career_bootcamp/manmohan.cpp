#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
	for(int j=1;j<=i;j++){
	(j==1||i==j)?
	cout<<"1":(i%2==0)?cout<<"0":cout<<"1";
	}
	cout<<endl;
	}
}