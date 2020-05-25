#include<iostream>
#include<vector>
using namespace std;
bool issubset(const vector<int>&v,int i=0,int sum=0,bool included=false){
	if(i==v.size()){
		return (sum==0&&included);	
	}
	bool inc=issubset(v,i+1,sum+v[i],true);
	bool exc=issubset(v,i+1,sum,included);
	return inc||exc;
}
int main(){
	int testcases;
	cin>>testcases;
	while(testcases--){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	
	if(issubset(v)){
	cout<<"Yes"<<endl;
	}
	else{
	cout<<"No"<<endl;
	}	
	}
	
}