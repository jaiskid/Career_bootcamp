#include<bits/stdc++.h>
const int MAX_CHAR=256;
using namespace std;
int distinct(string str){
	//This gonna to store the last occrurences of last index
	vector<int> last(MAX_CHAR,-1);
	int n=str.length();
	// this gonna to store the count
	int dp[n+1];
	dp[0]=1;
	for(int i=1;i<=n;i++){
	dp[i]=2*dp[i-1];
	if(last[str[i-1]]!=-1){
	dp[i]=dp[i]-dp[last[str[i-1]]];
	
	}
	last[str[i-1]]=(i-1);
	}
	return dp[n];
}
int main(){
	int t;
	cin>>t;
	while(t--){
	string s;
	cin>>s;
	cout<<distinct(s)<<endl;
	}
}