// https://leetcode.com/problems/arithmetic-slices/solution/
//time o(n*n*n)
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
vector<int>A;
ll n;
int numberOfArithmeticSlices() {
	int count = 0;
	for (int s = 0; s < n - 2; s++) {
		int d = A[s + 1] - A[s];
		for (int e = s + 2; e < n; e++) {
			int i = 0;
			for (i = s + 1; i <= e; i++)
				if (A[i] - A[i - 1] != d) {
					break;
				}
			if (i > e)
				count++;
		}
	}
	return count;
}
int onn() {
	int count = 0;
	for (int s = 0; s < n - 2; s++) {
		int d = A[s + 1] - A[s];
		for (int e = s + 2; e < n; e++) {
			if (A[e] - A[e - 1] == d)
				count++;
			else
				break;
		}
	}
	return count;
}
int sum = 0;
int recursive(vector<int>&A, int n) {
	if (n < 2) {
		return 0;

	}
	int ap = 0;
	if (A[n] - A[n - 1] == A[n - 1] - A[n - 2]) {
		ap = 1 + recursive(A, n - 1);
		sum += ap;
	}
	else {
		recursive(A, n - 1);
	}
	return ap;
}
int slicesdp(vector<int>&A) {
	int n = A.size();
	vector<int>dp;
	dp.resize(n, 0);
	int sum = 0;
	for (int i = 2; i < n; i++) {
		if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
			dp[i] = 1 + dp[i - 1];
			sum += dp[i];
		}
	}
	return sum;
}
int constantspacedp(vector<int>&A) {
	int dp = 0;
	int sum = 0;
	int n = A.size();
	for (int i = 2; i < n; i++) {
		if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
			dp = 1 + dp;
			sum += dp;
		}
		else {
			dp = 0;
		}
	}
	return sum;
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	A.resize(n);
	F(A, n);
	P(A, n);
	// cout << numberOfArithmeticSlices();
	// cout << onn();
	// recursive(A, n - 1);
	// cout << sum;
	// cout << slicesdp(A);
	cout << constantspacedp(A);
}