#include<iostream>
#include<cstring>
using namespace std;
 bool ispalindrome(char *a){
     int s=0;
     int e=strlen(a) - 1;
     while(s<e){
         if (a[s]!=a[e]){
             return false;
         }
         s++;
         e--;
     }
     return true;
 }
int main(){
    char a[1000];
    int n;cin>>n;
    for(int i=0;i<n;i++){
     cin>>a[i];
    }
   
    
    if(ispalindrome(a)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
