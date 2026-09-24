#include<iostream>
using namespace std;

int zeroOneKnapsack(int i,int n,int cap,vector<int>&weight,vector<int>&value,vector<vector<int>>&dp){
for(int i=0;i<=cap;i++){
    dp[n-1][cap]=0;
    
}
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