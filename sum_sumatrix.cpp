#include <iostream>
using namespace std;
int submatrixSum(int mat[100][100],int m,int n,int p,int q,int r,int s ){
    int sum[100][100];
    sum[0][0]=mat[0][0];
    //row wise 
    for(int j=1;j<m;j++){
        sum[0][j]=mat[0][j]+sum[0][j-1];
    }
    //col wise 
    for(int i=1;i<n;i++){
        sum[i][0]=mat[i][0]+sum[i-1][0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            sum[i][j]=mat[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    //p,q r,s (p,s) and total =sum[r][s]-sum[p-1][s]-sum[r][q-1]+sum[p-1][q-1];
    int total=sum[r][s];
    if(p-1>=0){
        total-=sum[p-1][s];
    }
    if(q-1>=0){
        total-=sum[r][q-1];
    }
    if(p-1>=0&&q-1>=0){
        total+=sum[p-1][q-1];
    }
    return total;
}
int main() {
    int n,m;
    cin>>n>>m;
    int mat[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    int p,q,r,s;
     cin>>p>>q>>r>>s;
     cout<<submatrixSum(mat,n,m,p,q,r,s);

}
