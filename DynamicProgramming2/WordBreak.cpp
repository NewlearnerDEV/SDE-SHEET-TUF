class Solution
{
public:
    bool rec(int ind, string &s, set<string> &w, vector<int> &dp)
    {
        if (ind == s.length())
        {
            return true;
        }
        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        string temp = "";
        for (int k = ind; k < s.length(); k++)
        {
            temp += s[k];
            if (w.find(temp) != w.end())
            {
                if (rec(k + 1, s, w, dp))
                {
                    return true;
                }
            }
        }
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> st;
        int n = s.length();
        vector<int> dp(n + 1, -1);
        for (auto itr : wordDict)
        {
            st.insert(itr);
        }
        return rec(0, s, st, dp);
    }
};