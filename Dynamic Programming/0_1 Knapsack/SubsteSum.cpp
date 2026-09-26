#include<iostream>
using namespace std;

/*
===========================================================
                    SUBSET SUM
===========================================================

Problem:
Given an array of positive integers and a target sum,
determine whether there exists a subset whose sum is
exactly equal to target.

Example:
nums = {3, 34, 4, 12, 5, 2}
target = 9

Answer = true
Subset = {4, 5}

-----------------------------------------------------------
DP STATE:

dp[i][target] / isPart(i, target)

Meaning:
Can we form 'target' using elements from index i onwards?

At every element:

1. TAKE
   target -> target - nums[i]

2. NOT TAKE
   target remains same

-----------------------------------------------------------
Complexity:

Time  : O(n * target)
Space : O(n * target) for 2D DP
        O(target) for optimized 1D DP
===========================================================
*/


// ========================================================
// 1. PURE RECURSION
// ========================================================

bool subsetSumRecursive(int i, int n, vector<int>& nums, int target) {

    // Target achieved
    if (target == 0)
        return true;

    // No elements left
    if (i == n)
        return false;

    // TAKE
    bool take = false;

    if (nums[i] <= target) {
        take = subsetSumRecursive(
            i + 1,
            n,
            nums,
            target - nums[i]
        );
    }

    // NOT TAKE
    bool notTake = subsetSumRecursive(
        i + 1,
        n,
        nums,
        target
    );

    return take || notTake;
}


// ========================================================
// 2. MEMOIZATION (TOP-DOWN)
// ========================================================

bool subsetSumMemo(
    int i,
    int n,
    vector<int>& nums,
    int target,
    vector<vector<int>>& dp
) {

    // Target achieved
    if (target == 0)
        return true;

    // No elements left
    if (i == n)
        return false;

    // Already calculated
    if (dp[i][target] != -1)
        return dp[i][target];

    // TAKE
    bool take = false;

    if (nums[i] <= target) {
        take = subsetSumMemo(
            i + 1,
            n,
            nums,
            target - nums[i],
            dp
        );
    }

    // NOT TAKE
    bool notTake = subsetSumMemo(
        i + 1,
        n,
        nums,
        target,
        dp
    );

    return dp[i][target] = take || notTake;
}


bool subsetSumMemoization(
    vector<int>& nums,
    int target
) {

    int n = nums.size();

    vector<vector<int>> dp(
        n,
        vector<int>(target + 1, -1)
    );

    return subsetSumMemo(
        0,
        n,
        nums,
        target,
        dp
    );
}


// ========================================================
// 3. TABULATION (2D)
// ========================================================

bool subsetSumTabulation(
    vector<int>& nums,
    int target
) {

    int n = nums.size();

    /*
        dp[i][j]

        Can we form sum j using elements
        from index i onwards?
    */

    vector<vector<bool>> dp(
        n + 1,
        vector<bool>(target + 1, false)
    );


    // Sum 0 is always possible
    // by selecting nothing.

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }


    /*
        i == n:

        No elements are available.

        Therefore:
        dp[n][j] = false for j > 0

        Already initialized as false.
    */


    for (int i = n - 1; i >= 0; i--) {

        for (int j = 1; j <= target; j++) {

            // NOT TAKE
            bool notTake = dp[i + 1][j];

            // TAKE
            bool take = false;

            if (nums[i] <= j) {
                take = dp[i + 1][j - nums[i]];
            }

            dp[i][j] = take || notTake;
        }
    }

    return dp[0][target];
}


// ========================================================
// 4. SPACE OPTIMIZED - TWO ROWS
// ========================================================

bool subsetSumTwoRows(
    vector<int>& nums,
    int target
) {

    int n = nums.size();

    vector<bool> dp(target + 1, false);

    // Previous state
    dp[0] = true;


    for (int i = 0; i < n; i++) {

        vector<bool> temp(
            target + 1,
            false
        );

        // Sum 0 is always possible
        temp[0] = true;

        for (int j = 1; j <= target; j++) {

            // NOT TAKE
            bool notTake = dp[j];

            // TAKE
            bool take = false;

            if (nums[i] <= j) {
                take = dp[j - nums[i]];
            }

            temp[j] = take || notTake;
        }

        dp = temp;
    }

    return dp[target];
}


// ========================================================
// 5. SPACE OPTIMIZED - 1D DP
// ========================================================

bool subsetSum1D(
    vector<int>& nums,
    int target
) {

    vector<bool> dp(
        target + 1,
        false
    );

    // Sum 0 is always possible
    dp[0] = true;


    for (int x : nums) {

        /*
            IMPORTANT:

            Iterate BACKWARD.

            This ensures that each element
            is used at most once.
        */

        for (int j = target; j >= x; j--) {

            dp[j] =
                dp[j] ||
                dp[j - x];
        }
    }

    return dp[target];
}


// ========================================================
// MAIN
// ========================================================

int main() {

    vector<int> nums = {
        3, 34, 4, 12, 5, 2
    };

    int target = 9;


    cout << "Recursive: "
         << subsetSumRecursive(
                0,
                nums.size(),
                nums,
                target
            )
         << endl;


    cout << "Memoization: "
         << subsetSumMemoization(
                nums,
                target
            )
         << endl;


    cout << "2D Tabulation: "
         << subsetSumTabulation(
                nums,
                target
            )
         << endl;


    cout << "Two Rows: "
         << subsetSumTwoRows(
                nums,
                target
            )
         << endl;


    cout << "1D DP: "
         << subsetSum1D(
                nums,
                target
            )
         << endl;


    return 0;
}