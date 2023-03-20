class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0, check = INT_MIN;
        ;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (check < sum)
            {
                check = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return check;
    }
};