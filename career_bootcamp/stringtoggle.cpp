#include<iostream>
#include<cstring>
using namespace std;
string toggle(string str){
	string ne="";
   
	for(int i=0;str[i]!='\0';i++){
		if(str[i]>='A'&&str[i]<='Z'){
			ne[i]=putchar(tolower(str[i]));
		}
		else if(str[i]>='a'&&str[i]<='z'){
			ne[i]=putchar(toupper(str[i]));
		}
	}
    
	return ne;
}
int main() {
	string s;
	cin>>s;
	cout<<toggle(s);
}