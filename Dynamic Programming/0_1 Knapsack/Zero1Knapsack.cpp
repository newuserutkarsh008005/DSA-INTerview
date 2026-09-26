#include<iostream>
using namespace std;

int zeroOneKnapsack(int i,int n,int cap,vector<int>&weight,vector<int>&value,vector<vector<int>>&dp){
if(i==n)return 0;
if(cap<0)return 0;
if(dp[i][cap]!=-1)return dp[i][cap];
if(cap-weight[i]<0){
   return dp[i][cap]=zeroOneKnapsack(i+1,n,cap,weight,value,dp);
}
else{
int take=0;

    take=value[i]+zeroOneKnapsack(i+1,n,cap-weight[i],weight,value,dp);

int nottake=zeroOneKnapsack(i+1,n,cap,weight,value,dp);
return dp[i][cap]= max(take,nottake);}
}
int main(){
vector<int> weight = {2, 3, 5, 7, 8, 10, 12, 15, 18, 20};
vector<int> value  = {6, 10, 12, 18, 22, 25, 30, 35, 40, 45};
int capacity = 40;

int n=value.size();
vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
cout<<zeroOneKnapsack(0,n,capacity,weight,value,dp);

    return 0;
}