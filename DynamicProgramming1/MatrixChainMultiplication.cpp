class Solution
{
public:
    int solve(int arr[], int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int mn = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int temp = solve(arr, i, k, dp) + solve(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
            if (temp < mn)
            {
                mn = temp;
            }
        }
        dp[i][j] = mn;
        return mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        int i = 1;
        int j = N - 1;
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
        int ans = solve(arr, i, j, dp);
        return ans;
    }
};