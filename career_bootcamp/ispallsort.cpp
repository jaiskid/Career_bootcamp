#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	string r;
	cin>>r;
	sort(r.begin(),r.end());
	if(s==r){
		cout<<"true";
	}else{
		cout<<"false";
	}
}