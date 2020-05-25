#include<iostream>
#include<cstring>
using namespace std;
void recursion(string s,string ans){
	if(s.size()==0){
	cout<<ans<<endl;
	return ;
	}
	char ch=s[0];
	string ros=s.substr(1);
	
	recursion(ros,ans);
	recursion(ros,ans+ch);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
	cin>>s;
	recursion(s," ");

	cout<<endl;
	}
	
}