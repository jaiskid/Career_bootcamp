#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	while(n!=0){
		int sum=0;
		int rem=n%10;
		sum+=rem;
		cout<<sum;
		n/=10;
	}
	
}