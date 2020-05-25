#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool ispossible(vector<ll>&board, ll time, ll k) {
	ll totaltime = time;
	ll i = 0;
	while (k > 0 and i < board.size()) {
		if (totaltime >= board[i]) {
			totaltime -= board[i];
			i++;
		}
		else {
			k--;
			totaltime = time;
		}

	}
	if (i < board.size()) {
		return false;
	}
	return true;
}
int main() {
	ll k;
	cin >> k;
	ll n;
	cin >> n;
	vector<ll> board(n);
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	ll lo = 0;
	ll hi = 0;
	for (int i = 0; i < n; i++) {
		hi += board[i];
	}
	ll ans = (ll)INT_MAX;
	while (lo <= hi) {
		ll mid = (lo + hi);
		mid >>= 1;
		if (ispossible(board, mid, k)) {
			ans = min(mid, ans);
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ans << endl;
}