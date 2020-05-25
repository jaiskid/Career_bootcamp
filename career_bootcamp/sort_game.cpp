#include<iostream>
using namespace std;
int main(){
	int min_sal;
	int n;
	cin>>min_sal>>n;
	string s;
	int salary;
	pair<string,int> emp[100005];
	for(int i=0;i<n;i++){
		cin>>s;
		cin>>salary;
		emp[i].first=s;
		emp[i].second=salary;
	}
	for(int i=0;i<n;i++){
	cout<<emp[i].first<<" "<<emp[i].second<<endl;
	}
}