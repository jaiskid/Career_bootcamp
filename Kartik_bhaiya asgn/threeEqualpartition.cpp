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
vector<int> threeEqualParts(vector<int>& A) {
	// Count no of 1's in the given array
	int n=A.size();
	int countNumberOfOnes = 0;
	for (int c : A)
		if (c == 1)
			countNumberOfOnes++;

	// If no 1 is found, that means we can return ans as {0, size-1}
	if (countNumberOfOnes == 0)
		return {0, n - 1};

	// If no of 1's is not a multiple of 3, then we can never find a possible partition since
	// there will be atkeast one partition that will have different no of 1's and hence
	// different binary representation
	// For example,
	// Given :
	// 0000110  110  110
	//       |  |    |
	//       i       j
	// Total no of ones = 6
	// 0000110         110      110
	//     |           |        |
	//     start       mid      end
	// Match starting from first 1, and putting 2 more pointers by skipping k 1's

	if (countNumberOfOnes % 3 != 0)
		return { -1, -1};

	// find size of each partition
	int k = countNumberOfOnes / 3;
	int i;

	// find the first 1 in the array
	for (i = 0; i < A.size(); i++)
		if (A[i] == 1)
			break;
	int start = i;

	// find (k+1)th 1 in the array
	int count1 = 0;
	for (i = 0; i < A.size(); i++)
	{
		if (A[i] == 1)
			count1++;
		if (count1 == k + 1)
			break;
	}
	int mid = i;

	//find (2*k +1)th 1 in the array
	count1 = 0;
	for (i = 0; i < A.size(); i++)
	{
		if (A[i] == 1)
			count1++;
		if (count1 == 2 * k + 1)
			break;
	}
	int end = i;

	// Match all values till the end of the array
	while (end < A.size() && A[start] == A[mid] && A[mid] == A[end])
	{
		start++; mid++; end++;
	}

	// Return appropriate values if all the values have matched till the end
	if (end == A.size())
		return {start - 1, mid};

	// otherwise, no such indices found
	return { -1, -1};
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int>A;
	A.resize(n);
	F(A, n);
	vector<int> ans = threeEqualParts(A);
	P(ans, ans.size());
}