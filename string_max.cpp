#include<bits/stdc++.h>
using namespace std;
char getMax_occurence(string str){
	int count[256]={0};
	int max=0;
	char ans;
	for(int i=0;i<str.size();i++){
	count[str[i]]++;
	if(max<count[str[i]]){
	max=count[str[i]];
	ans=str[i];
	}
	}
	return ans;
}
int main(){
	string s;
	cin>>s;
	cout<<getMax_occurence(s);
}