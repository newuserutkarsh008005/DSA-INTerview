#include<iostream>
using namespace std;

int zeroOneKnapsack(int n,int cap,vector<int>&weight,vector<int>&value,vector<vector<int>>&dp){
for(int i=0;i<=cap;i++){
dp[n][i]=0;
}
for(int i=0;i<=n;i++){
    dp[i][0]=0;
}
for(int i=n-1;i>=0;i--){
    for(int j=1;j<=cap;j++){
        if(weight[i]>j){
            dp[i][j]=dp[i+1][j];
        }
        else
        dp[i][j]=max(value[i]+dp[i+1][j-weight[i]],dp[i+1][j]);
    }
}
return dp[0][cap];

}
int main(){
vector<int> weight = {2, 3, 5, 7, 8, 10, 12, 15, 18, 20};
vector<int> value  = {6, 10, 12, 18, 22, 25, 30, 35, 40, 45};
int capacity = 40;

int n=value.size();
vector<vector<int>>dp(n+1,vector<int>(capacity+1,-1));
cout<<zeroOneKnapsack(n,capacity,weight,value,dp);

    return 0;
}