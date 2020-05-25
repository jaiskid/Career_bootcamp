#include<iostream>
using namespace std;
void park_check(char a[][100],int row,int col,int minstrength,int maxstrength){
	bool success=true;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
		if(minstrength>maxstrength){
		success=false;
		break;
		}
		char ch=a[i][j];
		if(ch=='.')
		maxstrength-=2;
		if(ch=='*')
		maxstrength+=5;
		if(ch=='#')
		break;
		if(j<col-1)
			maxstrength--;
		}

	}
	if(success){
		cout<<"Yes"<<endl<<maxstrength;
	}else{
		cout<<"No"<<endl;
	}
}
int main() {
	int row,col,minstrength,maxstrength;
	cin>>row>>col>>minstrength>>maxstrength;
	char a[100][100];
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>a[i][j];
		}
	}
	park_check(a,row,col,minstrength,maxstrength);
}