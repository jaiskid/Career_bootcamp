#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[n], brr[n], crr[n];
	int k = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> brr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i] == brr[j])
			{
				crr[k] = arr[i];
				k++;
				brr[j] = NULL;
				break;
			}
		}
	}
	sort (crr, crr + k);
	cout << "[";
	for (int i = 0; i < k; i++)
	{
		cout << crr[i];
		if (i < k - 1)
			cout << ", ";
		else if (i == k - 1)
			cout << "]";
	}
}