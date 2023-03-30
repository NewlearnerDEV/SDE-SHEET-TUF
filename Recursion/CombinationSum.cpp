class Solution
{
public:
    void rec(vector<int> &cand, int ind, int n, vector<vector<int>> &ans, vector<int> &ds, int target)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        if (ind == n)
        {
            return;
        }
        if (cand[ind] <= target)
        {
            ds.push_back(cand[ind]);
            rec(cand, ind, n, ans, ds, target - cand[ind]);
            ds.pop_back();
        }
        rec(cand, ind + 1, n, ans, ds, target);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> ds;
        rec(candidates, 0, n, ans, ds, target);
        return ans;
    }
};