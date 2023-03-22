class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int x;
        for (auto &ele : mp)
        {
            if (ele.second > (nums.size() / 2))
            {
                x = ele.first;
                break;
            }
        }
        return x;
    }
};