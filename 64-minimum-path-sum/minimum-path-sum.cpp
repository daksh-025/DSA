class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        
        // Base case
        if (i == 0 && j == 0) {
            return grid[0][0];
        }

        // Out of bounds
        if (i < 0 || j < 0) {
            return 1e9;
        }

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int up = grid[i][j] + f(i - 1, j, grid, dp);
        int left = grid[i][j] + f(i, j - 1, grid, dp);

        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // DP array
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(m - 1, n - 1, grid, dp);
    }
};