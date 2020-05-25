#include<iostream>
#include<vector>
using namespace std;
#define max 10000000
vector<bool> isPrime(max,true);
unsigned int primeArray[5761459];
void Generate_prime(){
	isPrime[0]=isPrime[1]=false;
	for(unsigned int i=2;i*i<=max;i++){
	if(isPrime[i]==true){
		for(unsigned int j=i;j*i<=max;j++){
		isPrime[i*j]=false;
		}
	}
	}
	unsigned int idx=1;
	primeArray[0]=2;
	for(int i=3;i<=max;i+=2){
	if(isPrime[i]){
	primeArray[idx++]=i;
	}
	}
}

int main(){
	Generate_prime();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<primeArray[n-1]<<endl;
	}
	

}