#include<iostream>
using namespace std;
int gcd(int a,int b){
	if(a==0){
		return b;

	}
	return gcd(b%a,a);
}
int cal_gcd(int *arr,int n){
	int result=arr[0];
	for(int i=0;i<n;i++){
		result=gcd(result,arr[i]);
		if(result==1)
		{
			return result;
		}
	}
	return result;
}
int main() {
	int n;
	cin>>n;
	int a[5761459];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<cal_gcd(a,n);

}