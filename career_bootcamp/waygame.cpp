#include<bits/stdc++.h>
using namespace std;
int count(int n) {
	int total[n + 1];
	int i;
	for (int j = 0; j < n + 1; j++) {
		total[j] = 0;
	}
	total[0] = 1;
	for (i = 3; i <= n; i++)
		total[i] += total[i - 3];
	for (i = 5; i <= n; i++)
		total[i] += total[i - 5];
	for (i = 10; i <= n; i++)
		total[i] += total[i - 10];
	return total[n];
}
int main() {
	int n;
	cin >> n;
	cout << count(n);
}