#include<iostream>
using namespace std;
int main() {
	int n, m;
	cin >> m >> n;
	int mx = 0;
	for (int i = m; i <= n; i++) {
		for (int j = m + 1; j <= n; j++) {
			if (mx < (i ^ j)) mx = i ^ j;
		}
	}
	cout << mx;
}