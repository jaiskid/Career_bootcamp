#include<bits/stdc++.h>
using namespace std;
int maxProd(vector<int>&nums) {
	if (nums.size() == 0)
		return 0;
	int maxProd = 1;
	int minProd = 1;
	int best = INT_MIN;
	for (int n : nums) {
		if (n < 0) {
			swap(maxProd, minProd);
		}
		maxProd = max(maxProd * n, n);
		minProd = min(minProd * n, n);
		best = max(best, maxProd);
	}
	return best;
}
int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cout << maxProd(nums);
}