#include<iostream>
using namespace std;

int zeroOneKnapsack(int n,int cap,vector<int>&weight,vector<int>&value,vector<int>&dp){

for(int i=n-1;i>=0;i--){
    vector<int>temp(cap+1,0);
    for(int j=1;j<=cap;j++){
        if(j<weight[i]){
            temp[j]=dp[j];
        }
        else{
            temp[j]=max(value[i]+dp[j-weight[i]],dp[j]);
        }
    }
    dp=temp;
}
return dp[cap];
}
int main(){
vector<int> weight = {2, 3, 5, 7, 8, 10, 12, 15, 18, 20};
vector<int> value  = {6, 10, 12, 18, 22, 25, 30, 35, 40, 45};
int capacity = 40;

int n=value.size();
vector<int>dp(capacity+1,0);

cout<<zeroOneKnapsack(n,capacity,weight,value,dp);

    return 0;
}