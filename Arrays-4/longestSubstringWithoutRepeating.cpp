class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<int, int> mp;
        int cnt = 0;
        int n = s.length();
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;

            while (mp[s[i]] > 1)
            {
                mp[s[k]]--;
                k++;
            }
            cnt = max(cnt, i - k + 1);
        }
        return cnt;
    }
};