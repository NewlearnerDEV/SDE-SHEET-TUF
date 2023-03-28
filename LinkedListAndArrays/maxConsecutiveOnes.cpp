class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int cnt = 0;
        int mn = INT_MIN;
        for (int i = 0; i < nums.size(); i++)

        {
            if (nums[i] == 1)
            {
                cnt++;
            }
            else
            {
                mn = max(mn, cnt);
                cnt = 0;
            }
        }

        return max(mn, cnt);
    }
};