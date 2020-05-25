#include<bits/stdc++.h>
using namespace std;
void sub_lexo(set<string>&st, string s) {
	if (s.size()==0)
		return;
	if (st.find(s) == st.end()) {
		st.insert(s);
		for (int i = 0; i < s.size(); i++) {
			string t = s;
			t.erase(i, 1);
			sub_lexo(st, t);
		}
	}
	return;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		set<string> st;
		sub_lexo(st, s);
		for (auto it = st.begin(); it != st.end(); it++) {
			cout << *it << endl;
		}
		cout << endl;
	}


}