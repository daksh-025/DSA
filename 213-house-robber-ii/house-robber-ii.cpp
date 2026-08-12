class Solution {
public:
    int f(int ind, vector<int>& ans, vector<int>& dp) {
        if (ind == 0) return ans[0];
        if (ind < 0) return 0;

        if (dp[ind] != -1) return dp[ind];

        int take = ans[ind] + f(ind - 2, ans, dp);
        int notTake = f(ind - 1, ans, dp);

        return dp[ind] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        // Edge case: only one house
        if (n == 1) return nums[0];

        vector<int> temp1, temp2;

        for (int i = 0; i < n; i++) {
            if (i != 0)
                temp1.push_back(nums[i]);  // [1 ... n-1]

            if (i != n - 1)
                temp2.push_back(nums[i]);  // [0 ... n-2]
        }

        // Separate DP arrays
        vector<int> dp1(n - 1, -1);
        vector<int> dp2(n - 1, -1);

        int case1 = f(n - 2, temp1, dp1);
        int case2 = f(n - 2, temp2, dp2);

        return max(case1, case2);
    }
};