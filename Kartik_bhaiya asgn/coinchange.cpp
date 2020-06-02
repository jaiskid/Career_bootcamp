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
int amount;
int coinschange(int i, vector<int>&coins, int amount) {
	if (amount == 0) {
		return 0;
	}
	if (i<coins.size() and amount > 0) {
		int maxVal = amount / coins[i];
		int minCost = INT_MAX;
		for (int x = 0; x <= maxVal; x++) {
			if (amount >= x * coins[i]) {
				int res = coinschange(i + 1, coins, amount - x * coins[i]);
				if (res != -1) {
					minCost = min(minCost, res + x);
				}
			}
		}
		return (minCost == INT_MAX) ? -1 : minCost;
	}
	return -1;
}
int dp[100009];

int topcoinchange(vector<int>&coins, int amount) {
	if (amount < 1) {
		return 0;
	}
	if (amount < 0)
	{
		return -1;
	}
	if (amount == 0) {
		return 0;
	}
	if (dp[amount - 1] != 0) {
		return dp[amount - 1];
	}
	int min = INT_MAX;
	for (int coin : coins) {
		int res = topcoinchange(coins, amount - coin);
		if (res >= 0 and res < min) {
			min = 1 + res;
		}
	}
	dp[amount - 1] = (min == INT_MAX) ? -1 : min;
	return dp[amount - 1];
}
int coinbottomup(vector<int>&coins, int amount) {
	long long int max = amount + 1;
    long long int *dp = new long long int[amount + 1];
    for(int i=0;i<max;i++){
    	dp[i]=INT_MAX;
    }
    dp[0] = 0;
	for (int i = 1; i <= amount; i++) {
		for (int j = 0; j < coins.size(); j++) {
			if (coins[j] <= i) {
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}
	
	return dp[amount] > amount ? -1 : dp[amount];
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
	memset(dp, 0, sizeof dp);
	// cout << minCoins(coins, amount);
	// cout << coinschange(0, coins, amount);
	// cout << topcoinchange(coins, amount);

	cout << coinbottomup(coins, amount);
	// cout << INT_MAX << endl;
}