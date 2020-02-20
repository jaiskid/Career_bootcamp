#include<iostream>
#include<bitset>
using namespace std;
int count_(int n)
{
	bitset<100> b1(n);
	return b1.count();
}
int main() {
int t;
cin>>t;
while(t--){
int n;
cin>>n;
cout<<count_(n)<<endl;
}



}