class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int ans;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        if (m == 1 && n == 1)
        {
            return 1;
        }
        else
        {
            ans = find(dp, m - 1, n - 1);
            return ans;
        }
    }
    int find(vector<vector<int>> &d1, int i, int j)
    {
        if (i == 0 && j == 0)
        {
            return 0;
        }
        if (i == 0 || j == 0)
        {
            return 1;
        }
        if (d1[i][j] != -1)
        {
            return d1[i][j];
        }
        d1[i][j] = find(d1, i - 1, j) + find(d1, i, j - 1);

        return d1[i][j];
    }
};