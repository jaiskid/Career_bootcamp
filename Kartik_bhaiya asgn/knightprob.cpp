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
double knightProbability(int N, int K, int sr, int sc) {
	double dp[N][N];
	int dr[] = {2, 2, 1, 1, -1, -1, -2, -2};
	int dc[] = {1, -1, 2, -2, 2, -2, 1, -1};
	dp[sr][sc] = 1;
	for (; K > 0; K--) {
		double dp2[N][N];
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				for (int k = 0; k < 8; k++) {
					int cr = r + dr[k];
					int cc = c + dr[k];
					if (0 <= cr and cr < N and 0 <= cc and cc < N) {
						dp2[cr][cc] += dp[r][c] / 8.0;
					}
				}

			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dp[i][j] = dp2[i][j];
			}
		}
	}
	double ans = 0.0;
	for (int row = 0; row < N; row++) {
		for (int x = 0; x < row; x++) {
			ans += x;
		}
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