//good subarrays

#include<iostream>
#include<cstring>
#define ll long long 
using namespace std;
int freq[1000005],arr[1000005];
int main() {
	int t;
	cin>>t;
	
	while(t--){
		memset(freq,0,sizeof(freq));
		int n;
		cin>>n;
		freq[0]=1;
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
			sum%=n;
			sum=(sum+n)%n;
			freq[sum]++;                                                                           
		}
		ll ans=0;
		for(int i=0;i<n;i++){
			ll m=freq[i];
			ans+=(m)*(m-1)/2;
		}
		cout<<ans<<endl;
	}
	return 0;
}