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
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size();
	int n = nums2.size();
	if (m > n) {
		swap(nums1, nums2);
		swap(m, n);
	}
	int imin = 0, imax = m,halflen = (m + n + 1) / 2;
	while (imin <= imax) {
		int i = (imin + imax) / 2;
		int j = halflen - i;
		if (i < imax and nums2[j - 1] > nums1[i]) {
			imin = i + 1; // i is too small
		}
		else if (i > imin and nums1[i - 1] > nums2[j]) {
			imax = i - 1; // i is too small
		}
		else {

			int maxLeft = 0;
			if (i == 0) {
				maxLeft = nums2[j - 1];
			}
			else if (j == 0) {
				maxLeft = nums1[i - 1];
			}
			else {
				maxLeft = max(nums1[i - 1], nums2[j - 1]);
			}
			if ((m + n) % 2 == 1) return maxLeft;


			int minRight = 0;
			if (i == m) { minRight = nums2[j]; }
			else if (j == n) { minRight = nums1[i]; }
			else { minRight = min(nums2[j], nums1[i]); }


			return (maxLeft + minRight) / 2.0;

		}
	}
	return 0.0;
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m;
	cin >> m;
	vector<int>nums1;
	nums1.resize(m);
	F(nums1, m);
	int n;
	cin >> n;
	vector<int>nums2;
	nums2.resize(n);
	F(nums2, n);
	cout << findMedianSortedArrays(nums1, nums2);
}