#include<iostream>
using namespace std;

class Solution {
public:

    // 1. Recursion
    bool solveRec(int i, int n, vector<int>& nums, int target) {
        if (target == 0) return true;
        if (i == n) return false;

        bool take = false;

        if (nums[i] <= target)
            take = solveRec(i + 1, n, nums, target - nums[i]);

        bool notTake = solveRec(i + 1, n, nums, target);

        return take || notTake;
    }


    // 2. Memoization
    bool solveMemo(int i, int n, vector<int>& nums,
                   int target, vector<vector<int>>& dp) {

        if (target == 0) return true;
        if (i == n) return false;

        if (dp[i][target] != -1)
            return dp[i][target];

        bool take = false;

        if (nums[i] <= target)
            take = solveMemo(i + 1, n, nums,
                             target - nums[i], dp);

        bool notTake = solveMemo(i + 1, n, nums,
                                 target, dp);

        return dp[i][target] = take || notTake;
    }


    // 3. 2D Tabulation
    bool solveTab(vector<int>& nums, int target) {

        int n = nums.size();

        vector<vector<bool>> dp(
            n + 1,
            vector<bool>(target + 1, false)
        );

        // Target 0 is always possible
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        for (int i = n - 1; i >= 0; i--) {

            for (int j = 1; j <= target; j++) {

                bool notTake = dp[i + 1][j];

                bool take = false;

                if (nums[i] <= j)
                    take = dp[i + 1][j - nums[i]];

                dp[i][j] = take || notTake;
            }
        }

        return dp[0][target];
    }


    // 4. 1D Space Optimized
    bool solve1D(vector<int>& nums, int target) {

        vector<bool> dp(target + 1, false);

        dp[0] = true;

        for (int x : nums) {

            // Backward -> each element used once
            for (int j = target; j >= x; j--) {
                dp[j] = dp[j] || dp[j - x];
            }
        }

        return dp[target];
    }


    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for (int x : nums)
            sum += x;

        // Equal partition impossible for odd sum
        if (sum % 2 != 0)
            return false;

        int target = sum / 2;
        int n = nums.size();

        // Choose whichever version you want

        // return solveRec(0, n, nums, target);

        // vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        // return solveMemo(0, n, nums, target, dp);

        // return solveTab(nums, target);

        return solve1D(nums, target);
    }
};