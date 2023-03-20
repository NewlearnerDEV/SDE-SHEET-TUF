class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int fs = intervals[0][0];
        int fe = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= fe)
            {
                fe = max(fe, intervals[i][1]);
            }
            else
            {
                ans.push_back({fs, fe});
                fs = intervals[i][0];
                fe = intervals[i][1];
            }
        }
        ans.push_back({fs, fe});
        return ans;
    }
};