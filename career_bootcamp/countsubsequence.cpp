#include<iostream>
using namespace std;
void subsequence(string s,string ans){
	if(s.size()==0){
		cout<<ans<<" ";
		return ;
	}
	char ch=s[0];
	string ros=s.substr(1);
	subsequence(ros,ans);
	subsequence(ros,ans+ch);
}

int count_subsequence(string s,string ans){
	if(s.size()==0){
		return 1;
	}
	
	char ch=s[0];
	string ros=s.substr(1);
	int count=0;
	count+=count_subsequence(ros,ans);
	count+=count_subsequence(ros,ans+ch);
	return count;
}
int main() {
	string s;
	cin>>s;
	subsequence(s,"");
	cout<<endl;
	cout<<count_subsequence(s,"");
}