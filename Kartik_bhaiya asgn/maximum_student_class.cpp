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
int maxStudents(vector<vector<char>>& seats) {
	int f[15][1000];
	int n = seats.size();
	int m = seats[0].size();
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= pow(2, m); j++) {
			f[i][j] = -1;
		}
	}
	f[0][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= pow(2, m); j ++) {
			if (f[i - 1][j] == -1) continue;
			int t[400];
			memset(t, 0, sizeof(t));
			t[0] = f[i - 1][j];
			f[i][0] = max(f[i][0], t[0]);
			for (int k = 0; k <= pow(2, m); k++) {
				for (int d = 1; d <= m; d++) {
					if (seats[i - 1][d - 1] == '#') continue;
					bool canPut = true;
					if (k & (1 << (d - 1))) canPut = false;
					if (d > 1 && (k & (1 << (d - 2)))) canPut = false;
					if (d < m && (k & (1 << (d)))) canPut = false;
					if (d > 1 && (j & (1 << (d - 2)))) canPut = false;
					if (d < m && (j & (1 << (d)))) canPut = false;
					if (canPut) {
						int nextState = k | (1 << (d - 1));
						if (t[nextState] < t[k] + 1) {
							t[nextState] = max(t[nextState], t[k] + 1);
							if (f[i][nextState] < t[nextState]) {
								f[i][nextState]  = t[nextState];
							}
						}
					}
				}
			}
		}
	}

	int ans = -1;
	for (int i = 0; i <= pow(2, m); i++) {
		ans = max(ans, f[n][i]);
	}
	return ans;
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
}