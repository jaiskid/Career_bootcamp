#include<iostream>
using namespace std;
int main(){
	int freq[2]={0};
	int k;
	cin>>k;
	string str;
	cin>>str;
	int n=str.length();
	int ans=0, left=0;
	for(int i=0;i<n;i++){
	char temp=str[i];
	freq[temp-'a']++;
	if(min(freq[0],freq[1])>k){
	freq[str[left]-'a']--;
	left++;
	}
	else{
	ans++;
	}
	}
	cout<<ans<<endl;
}