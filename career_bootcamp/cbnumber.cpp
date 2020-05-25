#include<iostream>
using namespace std;

bool valid(bool *visited, long int start, long int end) {
	for (int i = start; i < end; i++) {
		if (visited[i]) {
			return false;
		}
	}
	return true;
}
bool isCBNo(long int n) {

	if (n == 0 || n == 1) {
		return false;
	}

	long int arr[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
	long int k = sizeof(arr) / sizeof(long int);

	for (int i = 0; i < k; i++) {
		if (n == arr[i]) {
			return true;
		}
	}

	for (int i = 0; i < k; i++) {
		if (n % arr[i] == 0) {
			return false;
		}
	}

	return true;
}
int main() {
	int n;
	cin >> n;
	string str;
	cin >> str;
	long int count = 0;
	bool *visited = new bool[n];
	for (int len = 1; len <= n; len++) {
		for (int si = 0; si <= n - len; si++) {
			int ei = si + len;
			string ss = str.substr(si, ei - si);
			if (isCBNo(stol(ss)) && valid(visited, si, ei)) {
				count++;
				for (int i = si; i < ei; i++) {
					visited[i] = true;
				}
			}
		}
	}
	cout << count;
}
