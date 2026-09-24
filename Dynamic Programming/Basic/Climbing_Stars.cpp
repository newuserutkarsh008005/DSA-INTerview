#include<iostream>
using namespace std;
int cost(int i,int n,vector<int>&dp){
if(i==n)return 1;
if(i>n)return 0;
if(dp[i]!=-1)return dp[i];
return dp[i]=cost(i+1,n,dp)+cost(i+2,n,dp);

}
int main(){
    int n=5;
    vector<int>dp(n,-1);
    cout<<cost(0,n,dp);
    return 0;
}