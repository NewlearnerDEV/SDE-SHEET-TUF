class Solution
{
public:
    int rec(int ind, int prevind, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == nums.size())
        {
            return 0;
        }
        if (dp[ind][prevind + 1] != -1)
        {
            return dp[ind][prevind + 1];
        }
        int not_take = rec(ind + 1, prevind, nums, dp);
        int take = 0;
        if (prevind == -1 || nums[ind] > nums[prevind])
        {
            take = 1 + rec(ind + 1, ind, nums, dp);
        }
        dp[ind][prevind + 1] = max(take, not_take);
        return dp[ind][prevind + 1];
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int ans = rec(0, -1, nums, dp);
        return ans;
    }
};