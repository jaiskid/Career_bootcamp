#include<iostream>
#include<algorithm>
using namespace std;
bool isvalid(long stalls[],int n,int s,int current_ans){
	int cows=1;
	int currently_alloted=stalls[0];
	for(int i=1;i<n;i++){
	if(stalls[i]-currently_alloted>=current_ans){
	cows++,currently_alloted=stalls[i];;
	if(cows==s)
	return 1;
	}
	
	}
	return 0;
}
long minDist(long stalls[],int n,int k){
	int s=stalls[0];
	int e=stalls[n-1];
	int ans=0;
	int mid=0;
	while(s+1<e){
		mid=(s+e)/2;
		if(isvalid(stalls,n,k,mid)){
		s=mid+1;
		}
		else{
		e=mid-1;
		}
	}
	return s;
}

int main(){
	long  long int n;
	cin>>n;
	long long int k;
	cin>>k;
	long int stalls[100005];
	for(int i=0;i<n;i++){
	cin>>stalls[i];
	}
	
	sort(stalls,stalls+n);
	cout<<minDist(stalls,n,k);
}