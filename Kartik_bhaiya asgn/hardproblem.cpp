// https://codeforces.com/contest/706/problem/C
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
#define N 100001
string s[N][2];
ll dp[N][2];
int n, C[N], i, j, k;
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> C[i];
	for (i = 1; i <= n; i++) {
		cin >> s[i][0];
		s[i][1] = s[i][0];
		reverse(s[i][1].begin(), s[i][1].end());
		for (j = 0; j < 2; j++) {
			dp[i][j] = 1e18;
			for (k = 0; k < 2; k++)
				if (s[i][j] >= s[i - 1][k])
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * c[i]);
		}
	}
	long long ans = min(dp[n][0], dp[n][1]);
	printf("%lld\n", ans >= 1e18 ? -1 : ans);
}