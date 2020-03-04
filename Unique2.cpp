#include<iostream>
using namespace std;
void uniqueNumber(int *arr,int n){
	int res=0;
	for(int i=0;i<n;i++){
	res^=arr[i];
	}
	int pos=0;
	int temp=res;
	while(temp){
	if(temp&1){
	break;
	}
	pos++;
	temp>>1;
	}
	int mask=(1<<pos);
	int firstnumber=0;
	for(int i=0;i<n;i++){
	if(mask&arr[i]){
		firstnumber^=arr[i];
		}
	}
	int secondNumber=firstnumber^res;
	cout<<min(firstnumber,secondNumber)<<" "<<max(firstnumber,secondNumber);
}
int main(){
	int n;
	cin>>n;
	int arr[100005];
	for(int i=0;i<n;i++){
	cin>>arr[i];
	}
	uniqueNumber(arr,n);
}