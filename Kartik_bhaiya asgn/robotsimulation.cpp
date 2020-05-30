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
int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	int x = 0, y = 0, di = 0;
	unordered_set<pair<int, int>> obstacleSet;
	for (vector<int>obstacle : obstacles) {
		obstacleSet.insert(make_pair(obstacle[0], obstacle[1]));
	}
	int ans = 0;
	for (int cmd : commands) {
		if (cmd == -2)
			dp = (di + 3) % 4;
		else if (cmd == -1)
			di = (di + 1) % 4;
		else {
			for (int k = 0; k < cmd; ++k) {
				int nx = x + dx[di];
				int ny = y + dy[di];
				if (obstacleSet.find(make_pair(nx, ny)) == obstacleSet.end()) {
					x = nx;
					y = ny;
					ans = max(ans, x * x + y * y);
				}
			}
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