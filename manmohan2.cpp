#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x=-1;
	for(int i=1;i<=n;i++){
		if(x<1){
			for(int j=1;j<=i;j++){
				cout<<"1";
			}
		}
		else{
			for(int j=1;j<=i;j++){
				if(j==1||j==i){
					cout<<i-1;
				}
				else{
					cout<<0;
				}
			}
		}
		cout<<endl;
		x++;
	}
}