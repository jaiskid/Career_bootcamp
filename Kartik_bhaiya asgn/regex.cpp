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
bool isMatch(string s, string r) {
	int n = s.size();
	int m = r.size();

	int lookup[n + 1][m + 1];
	lookup[0][0] = true;
	//deals with the pattern like *a or a*b* or a*b*c
	for (int i = 2; i <m; i++) {
		if (r[i - 1] == '*') {
			lookup[0][i] = lookup[0][i - 2];
		}
	}
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <=m; j++) {
			if (r[j - 1] == '.' || r[j - 1] == s[i - 1]) {
				lookup[i][j] = lookup[i - 1][j - 1];
			}
			else if (r[j - 1] == '*') {
				lookup[i][j] = lookup[i][j - 2];
				if (r[j - 2] == '.' || r[j - 2] == s[i - 1]) {
					lookup[i][j] = lookup[i][j] | lookup[i - 1][j];
				}
			}
			else {
				lookup[i][j] = false;
			}
		}
	}
	return lookup[n][m];
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	string r;
	cin >> s >> r;
	cout << isMatch(s, r);
}