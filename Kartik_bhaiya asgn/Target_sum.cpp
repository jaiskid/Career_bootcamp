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
class Solution {
public:
	int dp[21][2001];
	int solve(int pos, vector<int>v, int tempSum, int s) {
		if (pos == v.size()) {
			return s == tempSum;
		}
		if (dp[pos][tempSum + 1000] != -1) {
			return dp[pos][tempSum + 1000];
		}
		int ans = solve(pos + 1, v, tempSum - v[pos], s) + solve(pos + 1, v, tempSum + v[pos], s);
		dp[pos][tempSum+1000] = ans;
		return ans;
	}
	int findTargetSumWays(vector<int>& nums, int S) {
		int n = nums.size();
		if (S > 1000)
			return 0;
		memset(dp, -1, sizeof dp);
		return solve(0, nums, 0, S);
	}
};
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Solution ob;
	vector<int> v = {1, 1, 1, 1, 1};
	cout << ob.findTargetSumWays(v, 3);
}