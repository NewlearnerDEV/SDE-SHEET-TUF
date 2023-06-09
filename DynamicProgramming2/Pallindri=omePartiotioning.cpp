class Solution
{
public:
    bool isPallindrome(string &str, int i, int j)
    {
        while (i < j)
        {
            if (str[i] != str[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int rec(int i, int n, string &str, vector<int> &dp)
    {

        if (i == n)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int mincost = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (isPallindrome(str, i, j))
            {
                int cost = 1 + rec(j + 1, n, str, dp);
                mincost = min(mincost, cost);
            }
        }
        return dp[i] = mincost;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<int> dp(n + 1, -1);
        int ans = rec(0, n, str, dp);
        return ans - 1;
    }
};