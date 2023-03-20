class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(1);
        ans.push_back(temp);
        for (int i = 1; i < numRows; i++)
        {
            vector<int> more;
            more.push_back(1);
            for (int j = 1; j < i; j++)
            {
                more.push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
            }
            more.push_back(1);
            ans.push_back(more);
        }
        return ans;
    }
};