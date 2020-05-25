#include<bits/stdc++.h>
using namespace std;
int *ans=NULL;
void queries(int *arr,int n){
	int max=*max_element(arr,arr+n);
	int count[max+1];
	
	memset(count, 0, sizeof(count)); 
  	for(int i=0;i<n;i++){
		count[arr[i]]++;
	}
	ans=new int[max+1];
	for(int i=1;i<=max;i++){
		for(int j=i;j<=max;j+=i){
			ans[i]+=count[j];

		}
	}
	return;	
}
int quer(int k){
	return ans[k];
}
int main(){
	int n;
	cin>>n;
	int arr[100005];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	queries(arr,n);
	int q;
	cin>>q;

	while(q--){
		int k;
		cin>>k;
		cout<<quer(k)<<endl;
	}
}