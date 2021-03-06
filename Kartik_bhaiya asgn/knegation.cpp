#include<bits/stdc++.h>
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
int largestAfterKnegation(vector<int>&A, int k) {
	nth_element(A.begin(), A.begin() + k, A.end());
	int remain = k;
	for (int i = 0; i < k; i++) {
		if (A[i] < 0) {
			A[i] = - A[i];
			--remain;
		}
	}
	return accumulate(A.cbegin(), A.cend(), 0) - (remain % 2) * *min_element(A.cbegin(), A.cend()) * 2;
}
int largestAfterKnegations(vector<int>&A, int k) {
	sort(A.begin(), A.end());
	int remain = k;
	for (int i = 0; i < k; i++) {
		if (A[i] < 0) {
			A[i] = -A[i];
			--remain;
		}
	}
	return accumulate(A.begin(), A.end(), 0) - (remain % 2) * *min_element(A.begin(), A.end()) * 2;
}
#define mod 1000000007
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
	int k;
	cin >> k;
	cout << largestAfterKnegations(A, k);
}