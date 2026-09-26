
#include<iostream>
using namespace std;

    int stn(int i, int n, vector<int>& stone, int &ans, int cur, vector<vector<int>>&dp) {
        cur=abs(cur);
        if (i == n) {
            return cur;
        }
        if(dp[i][cur]!=-1)return dp[i][cur];

        return dp[i][cur]=min(
            stn(i + 1, n, stone, ans, cur + stone[i],dp),
            stn(i + 1, n, stone, ans, cur - stone[i],dp)
        );
    }

    int lastStoneWeightII(vector<int>& stone) {
        int sum=0;
        for(int i:stone){
            sum+=i;
        }
        int ans = INT_MAX;
        int n = stone.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));

        for(int i=0;i<=sum;i++){
            dp[n][i]=i;
        }
        int cur=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=sum;j++){
                int a=abs(j+stone[i]);
                int b=abs(j-stone[i]);
              if(a<=sum){
                dp[i][j]=min(dp[i+1][a],dp[i+1][b]);
              }
              else dp[i][j]=dp[i+1][b];
            }
        }
        return dp[0][0];
    }
int main(){
    vector<int>stone={31,26,33,21,40};
    cout<<lastStoneWeightII(stone);
    return 0;
}