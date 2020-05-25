#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int no;
	int bitfreq[64]={0};
	int j=0;
	for(int i=0;i<n;i++){
	cin>>no;
	while(no>0){
		int last_bit=no&1;
		bitfreq[j]=last_bit;
		j++;
		no>>=1;
		}
	}
	int p=1;
	long int ans=0;
	for(int i=0;i<64;i++){
		 bitfreq[i]=bitfreq[i]%3;
		 ans+=bitfreq[i]*p;
		 p<<=1;
	}
	cout<<ans<<endl;
}