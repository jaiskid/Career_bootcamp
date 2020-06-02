#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <deque>
#include <bitset>
#include <climits>
#include <cstdio>
#include <list>
#include <iomanip>
using namespace std;

#define ll long long int
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 200001
#define mod 1000000007
int strangePrinter(string s) {
	if (s.size() == 0) {
		return 0;
	}
	int n = s.size();
	int dp[n][n]={};
	for (int i = 0; i < n; i++) {
		// dp[i][j] stand for minimum turns we need for string from index i to index j
		//we need 1 turn to paint a single character
		dp[i][i] = 1;
		if (i < n - 1) {
			dp[i][i + 1] = (s[i] == s[i + 1]) ? 1 : 2;
		}
	}
	for (int len = 2; len < n; len++) {
		for (int start = 0; start + len < n; start++) {
			// print each character one time
			dp[start][start + len] = len + 1;
			for (int k = 0; k < len; k++) {
				int temp = dp[start][start + k] + dp[start + k + 1][start + len];
				dp[start][start + len] = min(dp[start][start + len], (s[start + k] == s[start + len] )? temp - 1 : temp);
			}
		}
	}
	return dp[0][n - 1];
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	cin >> s;
	cout << strangePrinter(s);
}