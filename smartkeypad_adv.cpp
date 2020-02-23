#include<bits/stdc++.h>
using namespace std;
string table[]={" ",".+@$","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

void keypad(string s,string ans){
	if(s.size()==0){
	for(string ss: searchIn){
	if(ss.find(ans)){
	cout<<ss<<endl;
		}
	}
		return;
	}
	char ch=s[0];
	string ros=s.substr(1);
	string code=table[ch-'0'];
	for(int i=0;i<code.size();i++){
	keypad(ros,ans+code[i]);
	}
}
int main(){
	string s;
	cin>>s;
	keypad(s," ");
}