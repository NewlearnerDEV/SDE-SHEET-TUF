class Solution
{
public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int rec(int n, int k, vector<vector<int>> &dp)
    {
        if (k == 0 || k == 1)
        {
            return k;
        }
        if (n == 1)
        {
            return k;
        }
        if (dp[n][k] != -1)
        {
            return dp[n][k];
        }
        int mn = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            int attempt = 1 + max(rec(n - 1, j - 1, dp), rec(n, k - j, dp));
            mn = min(mn, attempt);
        }
        return dp[n][k] = mn;
    }
    int eggDrop(int n, int k)
    {
        // your code here
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        int ans = rec(n, k, dp);
        return ans;
    }
};