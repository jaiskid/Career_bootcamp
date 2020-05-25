#include<bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
	int max_area = 0, i = 0, size = heights.size();
	for (stack<int> stk; i < size || !stk.empty();)
		if (stk.empty() || (i != size and heights[stk.top()] <= heights[i])) stk.push(i++);
		else {
			int tp = stk.top(); stk.pop();
			max_area = max(max_area, heights[tp] * (stk.empty() ? i : i - stk.top() - 1));
		}
	return max_area;

}
int main() {
	int n;
	cin >> n;
	vector<int>nums;
	nums.resize(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	cout << largestRectangleArea(nums);
}