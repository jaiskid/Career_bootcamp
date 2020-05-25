#include<iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int num = n ^ m;
	int msb = 0;
	while (num != 0) {
		num = num >> 1;
		msb++;
	}
	int result = 1;
	while (msb--) {
		result = result <<= 1;
	}
	cout << result - 1 << endl;
}