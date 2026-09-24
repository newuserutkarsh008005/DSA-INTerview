#include<iostream>
using namespace std;

int cost(int i,int n,vector<int>&nums,vector<int>&dp,bool avl){
    if(i==n)return 0;
    if(!avl){
        return cost(i+1,n,nums,dp,true);
    }
    if(dp[i]!=-1)return dp[i];
    
    int take=cost(i+1,n,nums,dp,false)+nums[i];
    int nottake=cost(i+1,n,nums,dp,true);
    return dp[i]=max(take,nottake);
}
int main(){


   vector<int>nums={1,2,3,1};
        int n=nums.size();
        vector<int>dp(n,-1);
        cout<< cost(0,n,nums,dp,true);
    
}