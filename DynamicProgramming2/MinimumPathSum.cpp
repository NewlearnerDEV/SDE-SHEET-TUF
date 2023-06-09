class Solution
{
public:
    int rec(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
        {
            return grid[i][j];
        }
        if (i < 0 || j < 0)
        {
            return 1e9;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int up = rec(i - 1, j, grid, dp) + grid[i][j];
        int left = rec(i, j - 1, grid, dp) + grid[i][j];
        dp[i][j] = min(up, left);
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int ans = rec(m - 1, n - 1, grid, dp);
        return ans;
    }
};