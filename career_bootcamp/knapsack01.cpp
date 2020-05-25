#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
static int t[N][N];
int wt[N];
int val[N];
int knapsack(int n, int W) {
	if (n == 0 || W == 0) {
		return 0;
	}
	if (t[n][W] != -1) {
		return t[n][W];
	}
	else if (wt[n - 1] <= W) {
		return t[n][W] = max(val[n - 1] + knapsack(n - 1, W - wt[n - 1]), knapsack(n - 1, W));
	}
	else if (wt[n - 1] > W) {
		return t[n][W] = knapsack(n - 1, W);
	}
	return t[n][W];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int W;
	cin >> W;
	for (int i = 0; i < n; i++) {
		cin >> wt[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> val[i];
	}
	memset(t, -1, sizeof t);
	cout << knapsack(n, W);
}
