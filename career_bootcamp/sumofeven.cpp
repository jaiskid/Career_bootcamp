#include<bits/stdc++.h>
using namespace std;
void sumofodd(int n){
	bool isodd=(n&1)?1:0;
	int sume=0,sumo=0;
	while(n!=0){
	if(isodd){
		sumo+=n%10;
	}else{
	sume+=n%10;
	}
	isodd=!isodd;
	n/=10;
	}
	cout<<sumo<<endl;
	cout<<sume;
}
int main(){
int n;
cin>>n;
sumofodd(n);	
}