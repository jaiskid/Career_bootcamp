#include<iostream>
using namespace std;
void lexiographical(int n,int a){
	if(a>n)
	return;
	cout<<a<<" ";
	int i=0;
	if(a==0)
	i=1;
	for(;i<=9;i++)
	lexiographical(n,a*10+i);

}
int main() {
	int n;
	cin>>n;
	lexiographical(n,0);
}