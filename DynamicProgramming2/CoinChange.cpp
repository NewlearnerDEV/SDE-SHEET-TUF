class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        if (n == 1)
        {
            if (amount % coins[0] == 0)
            {
                return amount / coins[0];
            }
            else
            {
                return -1;
            }
        }
        for (int i = 0; i <= amount; i++)
        {
            dp[0][i] = INT_MAX - 1;
        }
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= amount; i++)
        {
            if (i % coins[0] == 0)
            {
                dp[1][i] = i / coins[0];
            }
            else
            {
                dp[1][i] = INT_MAX - 1;
            }
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if (dp[n][amount] == 2147483646)
        {
            return -1;
        }
        return dp[n][amount];
    }
};