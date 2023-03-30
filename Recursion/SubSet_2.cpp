class Solution
{

public:
    void subset(vector<int> &nums, int ind, int n, vector<vector<int>> &ans, vector<int> &ds)
    {

        ans.push_back(ds);

        for (int i = ind; i < n; i++)
        {
            if (i != ind && nums[i - 1] == nums[i])
            {
                continue;
            }
            ds.push_back(nums[i]);
            subset(nums, i + 1, n, ans, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> ds;
        int n = nums.size();
        subset(nums, 0, n, ans, ds);
        return ans;
    }
};