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
        for (int i = ind; i < n; i++)
        {
            if (i != ind && cand[i] == cand[i - 1])
            {
                continue;
            }
            if (cand[i] > target)
            {
                break;
            }
            ds.push_back(cand[i]);
            rec(cand, i + 1, n, ans, ds, target - cand[i]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        rec(candidates, 0, n, ans, ds, target);
        return ans;
    }
};