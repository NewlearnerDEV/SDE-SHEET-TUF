class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        map<int, int> mp;
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            sum += A[i];
            if (sum == 0)
            {
                cnt = i + 1;
            }
            if (mp.find(sum) != mp.end())
            {
                cnt = max(cnt, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;// storing prefix sum upto that index
            }
        }
        return cnt;
    }
};
