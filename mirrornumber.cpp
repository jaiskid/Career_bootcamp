#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[1000005]={0};
	int i=0;
	while(n!=0){
	int rem=n%10;
	arr[i]=rem;
	i++;
	n/=10;
	}
	for(int j=0;j<i;j++){

		cout<<arr[j];
	}

}