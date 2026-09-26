#include <iostream>
using namespace std;

class Solution {
public:

    // 1. Recursion
    int solveRec(int i, int n, vector<int>& nums, int target) {

        if (i == n)
            return target == 0;

        int add = solveRec(i + 1, n, nums, target - nums[i]);
        int sub = solveRec(i + 1, n, nums, target + nums[i]);

        return add + sub;
    }


    // 2. Memoization
    int solveMemo(int i, int n, vector<int>& nums,
                  int target, vector<vector<int>>& dp,
                  int offset) {

        if (i == n)
            return target == 0;

        int idx = target + offset;

        if (dp[i][idx] != -1)
            return dp[i][idx];

        int add = solveMemo(
            i + 1, n, nums,
            target - nums[i],
            dp, offset
        );

        int sub = solveMemo(
            i + 1, n, nums,
            target + nums[i],
            dp, offset
        );

        return dp[i][idx] = add + sub;
    }


    // 3. 2D Tabulation
    int solveTab(vector<int>& nums, int target) {

        int n = nums.size();

        int sum = 0;
        for (int x : nums)
            sum += x;

        if (abs(target) > sum)
            return 0;

        int offset = sum;

        vector<vector<int>> dp(
            n + 1,
            vector<int>(2 * sum + 1, 0)
        );

        dp[n][offset] = 1;

        for (int i = n - 1; i >= 0; i--) {

            for (int j = -sum; j <= sum; j++) {

                int idx = j + offset;

                int add = 0;
                int sub = 0;

                if (j - nums[i] >= -sum &&
                    j - nums[i] <= sum) {
                    add = dp[i + 1][j - nums[i] + offset];
                }

                if (j + nums[i] >= -sum &&
                    j + nums[i] <= sum) {
                    sub = dp[i + 1][j + nums[i] + offset];
                }

                dp[i][idx] = add + sub;
            }
        }

        return dp[0][target + offset];
    }


    // 4. 1D Space Optimized
    int solve1D(vector<int>& nums, int target) {

        int sum = 0;

        for (int x : nums)
            sum += x;

        if (abs(target) > sum)
            return 0;

        int offset = sum;

        vector<int> dp(2 * sum + 1, 0);
        dp[offset] = 1;

        for (int x : nums) {

            vector<int> temp(2 * sum + 1, 0);

            for (int s = -sum; s <= sum; s++) {

                if (dp[s + offset] == 0)
                    continue;

                temp[s + x + offset] += dp[s + offset];
                temp[s - x + offset] += dp[s + offset];
            }

            dp = temp;
        }

        return dp[target + offset];
    }


    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0;

        for (int x : nums)
            sum += x;

        if (abs(target) > sum)
            return 0;

        int n = nums.size();

        // Recursion
        // return solveRec(0, n, nums, target);

        // Memoization
        // vector<vector<int>> dp(
        //     n,
        //     vector<int>(2 * sum + 1, -1)
        // );
        // return solveMemo(
        //     0, n, nums, target, dp, sum
        // );

        // 2D Tabulation
        // return solveTab(nums, target);

        // 1D Space Optimized
        return solve1D(nums, target);
    }
};