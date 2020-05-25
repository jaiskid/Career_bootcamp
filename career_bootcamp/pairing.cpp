#include<bits/stdc++.h>
using namespace std;
const int n = 100001;
int parent[n], sz[n];
int get_parent(int x) {
	if (x == parent[x]) {
		return x;
	} else {
		return parent[x] = get_parent(parent[x]);
	}
}
void unite(int x, int y) {
	int super_x = get_parent(x);
	int super_y = get_parent(y);
	if (super_x != super_y) {
		parent[super_y] = super_x;
		sz[super_x] += sz[super_y];
		sz[super_y] = 0;
	}
}
void init() {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
}
int32_t main()
{
	//  code starts
	init();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		unite(x, y);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (n - sz[get_parent(i)]);
	}
	// every edge is counted twice
	cout << ans / 2;
}