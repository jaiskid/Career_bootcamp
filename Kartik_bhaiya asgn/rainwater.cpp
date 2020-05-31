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

// int trap(vector<int>&height) {
// 	int maxarea = 0;
// 	int left_max = 0;
// 	int right_max = 0;
// 	for (int i = 0; i < height.size(); i++) {
// 		left_max = max(height[i], left_max);
// 	}
// 	for (int i = height.size() - 1; i >= 0; i--) {
// 		right_max = max(right_max, height[i]);
// 	}
// 	for (int i = 0; i < height.size(); i++) {
// 		ans += max(left_max, right_max) - height[i];
// 	}
// 	return ans;
// }
int trap(vector<int>height) {
	if (height.size() == 0) {
		return 0;
	}
	int ans = 0;
	int n = height.size();
	vector<int>left_max(n), right_max(n);
	left_max[0] = height[0];
	for (int i = 1; i < n; i++) {
		left_max[i] = max(left_max[i], height[i]);
	}
	right_max[n - 1] = height[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		right_max[i] = max(height[i], right_max[i + 1]);
	}
	for (int i = 1; i < n - 1; i++) {
		ans += min(left_max[i], right_max[i]) - height[i];
	}
	return ans;

}
int trap2(vector<int>&height) {
	stack<int>st;
	int ans = 0, current = 0;
	while (current < height.size()) {
		while (!st.empty() and height[st.top()] < height[current]) {
			int top = st.top();
			st.pop();
			if (st.empty()) {
				break;
			}
			int distance = current - st.top() - 1;
			int bounded_height = min(height[current], height[st.top()]) - height[top];
			ans += distance * bounded_height;
		}
		st.push(current++);
	}
	return ans;
}
int trap3(vector<int>&height) {
	int left = 0, left_max = 0, right_max = 0, ans = 0;
	int right = height.size() - 1;
	while (left < right) {
		if (height[left] < height[right]) {
			height[left] >= left_max ? (left_max = height[left]) :
			ans += left_max - height[left];
			++left;
		}
		else {
			height[right] >= right_max ? (right_max = height[right]) :
			ans += (right_max - height[right]);
			--right;
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
	int n;
	cin >> n;
	vector<int>height;
	height.resize(n);
	F(height, n);
	cout << trap3(height);
}