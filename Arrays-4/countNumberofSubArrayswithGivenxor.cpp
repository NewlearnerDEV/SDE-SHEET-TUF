int Solution::solve(vector<int> &A, int B)
{
    unordered_map<int, int> mp;
    int cnt = 0, xorr = 0;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        xorr = xorr ^ A[i];
        if (xorr == B)
        {
            cnt++;
        }
        if (mp.find(xorr ^ B) != mp.end())
        {
            cnt += mp[xorr ^ B];
        }
        mp[xorr] += 1; // storing the count of prefix xor
    }                  // if a^b=c then ^b both side ->a=b^c
    return cnt;
}
