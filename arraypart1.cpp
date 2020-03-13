#include<iostream>
using namespace std;
int arrayPart(vector<int>&num){
	sort(num.begin(),num.end());
	auto  result=0;
	for(auto i=0;i<num.size();i+=2)
	{
	result+=num[i];
	}
	return result;
}
int main(){
	vector<int> num;
	int n;cin>>n;
	while(n--){
	int data;
	cin>>data;
	num.push_back(data);
	}
	cout<<arrayPart(num);
}