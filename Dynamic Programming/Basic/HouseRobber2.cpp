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

    vector<int>nums={2,3,2};
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp(n,-1);
        int ans1=cost(0,n-1,nums,dp,true);
        int ans2=cost(1,n,nums,dp1,true);
        cout<< max(ans1,ans2);

        return 0;
    }

    