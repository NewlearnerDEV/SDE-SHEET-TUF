class Solution
{
public:
    int rec(string &a, string &b, int n, int m, vector<vector<int>> &dp)
    {
        if (n == 0 || m == 0)
        {
            return 0;
        }
        if (dp[n][m] != -1)
        {
            return dp[n][m];
        }
        if (a[n - 1] == b[m - 1])
        {
            dp[n][m] = 1 + rec(a, b, n - 1, m - 1, dp);
        }
        else
        {
            dp[n][m] = max(rec(a, b, n - 1, m, dp), rec(a, b, n, m - 1, dp));
        }
        return dp[n][m];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = rec(text1, text2, n, m, dp);
        return ans;
    }
};