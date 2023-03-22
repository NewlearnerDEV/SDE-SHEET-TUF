class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {

        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        vector<int> x;
        for (auto &ele : mp)
        {
            if (ele.second > (nums.size() / 3))
            {
                x.push_back(ele.first);
            }
        }
        return x;
    }
};