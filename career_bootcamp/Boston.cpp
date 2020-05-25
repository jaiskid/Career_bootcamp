#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, sum=0, sum_n=0;  
    cin>>n;
    int temp=n;
    while(temp>0)
    {
        sum_n=sum_n+(temp%10);
        temp/=10;
    }
    while (n%2 == 0)
    {
        sum+=2;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
           int temp1=i;
            while(temp1>0)
    {
        sum=sum+(temp1%10);
        temp1/=10;
    }

            n = n/i;
        }
    }

    if (n > 2)
    {  while(n>0)
    {
        sum=sum+(n%10);
        n/=10;
    }}

    if(sum_n==sum)
        cout<<"1";
    else
        cout<<"0";
    return 0;
}