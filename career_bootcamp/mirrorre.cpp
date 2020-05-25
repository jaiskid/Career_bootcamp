#include<iostream>
#include<cmath>
using namespace std;
bool checker(long int n){
int qwerty=n;
	long int x=0;
	long int r=0;
	while(n>0){
	long int a=n%10;
	n/=10;
	x++;
	a--;
	if(a!=4)
	r+=(pow(10,a)*x);
	else
	r+=10000*x;
	}
	if(r==qwerty)
	return true;
	else
	return false;
}
int main(){
	int t;
	cin>>t;
	while(t--){
	long int n;
	cin>>n;
	(checker(n))?cout<<"true\n":cout<<"false\n";
	}
}