#include<bits/stdc++.h>
using namespace std;
void reverse(int n){
	int even=0,odd=0,count=1,rem=0;
	while(n!=0){
	rem=n%10;
	n/=10;
	if(count%2==0){
	even+=rem;
	}
	else{
	odd+=rem;
	}
	count++;
	}

	cout<<odd<<endl;
	cout<<even;
}
int main(){
	int n;
	cin>>n;
	reverse(n);
}