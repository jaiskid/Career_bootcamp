#include<iostream>
#include<cstring>
using namespace std;

void remove(char *s){
	int n;
	n=strlen(s);
	int k=0;
	char prev='\0';
	//loop through the string
	for(int i=0;i<n;i++){
		//if current char is different than the previous char
	if(prev!=s[i])
		//set distinct char at index k and increment it
	s[k++]=s[i];
		// update previous char to current char for next iteration of loop
	prev=s[i];
	}
	//null terminate the resultant string 
	s[k]='\0';
} 
int main(){
	char s[1000005];
	cin>>s;
	remove(s);
	cout<<s;
}