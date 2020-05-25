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
ll n;
vector<int>coins;
ll amount;
int coinChange(vector<int>& coins, int amount) {
	if (amount == 0)
		return 0;
	int res = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (coins[i] <= amount) {
			int sub_res = coinChange(coins, amount - coins[i]);
			if (sub_res != INT_MAX and sub_res + 1 < res)
				res = sub_res + 1;
		}
	}
	int ans = -1;
	return (res == INT_MAX) ? ans : res;
}
int minCoins(vector<int>&coins, int amount) {
	vector<int> t(amount + 1, numeric_limits<int>::max());
	t[0] = 0;
	
	for (int i = 0; i <n; i++) {
		for (int j = 1; j <=amount; j++) {
			if (coins[i] <= j) {
				int sub_res = t[j- coins[i]];
				if (sub_res != INT_MAX and sub_res + 1 < t[j])
					t[j] = sub_res + 1;
			}
		}
	}
	return t[amount] == INT_MAX ? -1 : t[amount];
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	coins.resize(n);
	F(coins, n);
	cin >> amount;
	cout << minCoins(coins, amount);
	cout << endl;
	// cout << INT_MAX << endl;
}