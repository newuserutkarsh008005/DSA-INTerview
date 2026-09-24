#include<iostream>
using namespace std;
int main(){
    int n=10;
    int a=0;
    int b=1;
    for(int i=2;i<=n;i++){
        int ans=a+b;
        a=b;
        b=ans;
        
    }
    cout<<b;
    return 0;
}