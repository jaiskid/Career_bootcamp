#include<bits/stdc++.h>
using namespace std;
int stringToint(string str) {
	if (str.length() == 1)
		return (str[0] - '0');
	double y = stringToint(str.substr(1));
	double x = str[0] - '0';
	x = x * pow(10, str.length() - 1) + y;
	return int(x);
}
int main() {
	string str;
	cin >> str;
	cout << stringToint(str) << endl;

}
