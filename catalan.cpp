#include<bits/stdc++.h> 
using namespace std; 

int binomialCoeff(int n, int k) 
{ 
    long long int C[k+1]; 
    memset(C, 0, sizeof(C)); 

    C[0] = 1; // nC0 is 1 

    for (int i = 1; i <= n; i++) 
    { 
        // Compute next row of pascal triangle using 
        // the previous row 
        for (int j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j-1]; 
    } 
    return C[k]; 
} 
int main() 
{ 
    int n;
    cin>>n;
    cout<<binomialCoeff(2*n,n)/(n+1)<<endl;
    return 0; 
} 
