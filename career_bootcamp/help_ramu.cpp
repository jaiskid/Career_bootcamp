#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	int c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	int n,m;
	cin>>n>>m;
	int rickshaw[n];
	int cab[m];
	for(int i=0;i<n;i++){
		cin>>rickshaw[i];
	}0
	for(int i=0;i<m;i++){
		cin>>cab[i];
	}
	int rickshawcost=0;
	for(int i=0;i<n;i++){
		rickshawcost+=min(c1*rickshaw[i],c2);
	}
	rickshawcost=min(rickshawcost,c3);
	int cabcost=0;
	 for(int i=0;i<m;i++){
		cabcost+=min(c1*cab[i],c2);
	}
	cabcost=min(cabcost,c3);
	int result=min(c4,cabcost+rickshawcost);
	cout<<result<<endl;	
	}
	
}