class Solution
{
public:
    bool subsum(vector<int> &nums, int n, int sum, vector<vector<int>> &dp)
    {

        if (n == 0 && sum > 0)
        {
            return false;
        }
        if (sum == 0)
        {
            return true;
        }
        if (dp[n][sum] != -1)
        {
            return dp[n][sum];
        }

        if (nums[n - 1] <= sum)
        {
            return dp[n][sum] = subsum(nums, n - 1, sum - nums[n - 1], dp) || subsum(nums, n - 1, sum, dp);
        }
        else
        {
            return dp[n][sum] = subsum(nums, n - 1, sum, dp);
        }
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
        }

        if (sum % 2 == 1)
        {
            return false;
        }
        else
        {
            vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, -1));
            return subsum(nums, n, sum / 2, dp);
        }
    }
};