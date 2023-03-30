class Solution
{
public:
    bool pallindrome(int i, int ind, string s)
    {
        while (ind < i)
        {
            if (s[i] != s[ind])
            {
                return false;
            }
            ind++;
            i--;
        }
        return true;
    }
    void rec(string s, int ind, int n, vector<vector<string>> &ans, vector<string> &ds)
    {
        if (ind == n)
        {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < n; i++)
        {
            if (pallindrome(i, ind, s))
            {
                // cout<<ind<<i<<endl;
                string k = s.substr(ind, i + 1 - ind); // second argument mein length hota hi
                // cout<<k<<endl;
                ds.push_back(k);
                rec(s, i + 1, n, ans, ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        int n = s.length();
        vector<vector<string>> ans;
        vector<string> ds;
        rec(s, 0, n, ans, ds);
        return ans;
    }
};