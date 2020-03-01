#include<iostream>
using namespace std;
bool string_ispallindrome(string str){
	int s=0;
	int e=str.length()-1;
	while(s<e){
		if(str[e]!=str[s]){
			return false;
		}
		s++;
		e--;
	}
	return true;
}
int main() {
	string str;
	cin>>str;
	(string_ispallindrome(str))?cout<<"true\n":cout<<"false\n";
}
