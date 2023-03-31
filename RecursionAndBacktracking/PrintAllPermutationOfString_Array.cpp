class Solution
{
public:
    void rec(vector<int> &nums, int ind, int n, vector<vector<int>> &ans)
    {
        if (ind == n)
        {
            ans.push_back(nums);
            return;
        }
        for (int i = ind; i < n; i++)
        {
            swap(nums[ind], nums[i]);
            rec(nums, ind + 1, n, ans);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        rec(nums, 0, n, ans);
        return ans;
    }
};