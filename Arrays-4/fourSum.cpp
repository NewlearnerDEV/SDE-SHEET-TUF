class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                long long rem = (long long)target - (long long)nums[i] - (long long)nums[j];
                int start = j + 1;
                int end = n - 1;
                while (start < end)
                {
                    if (nums[start] + nums[end] < rem)
                    {
                        start++;
                    }
                    else if (nums[start] + nums[end] > rem)
                    {
                        end--;
                    }
                    else
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[start]);
                        temp.push_back(nums[end]);
                        st.insert(temp);
                        start++;
                        end--;
                    }
                }
            }
        }
        for (auto itr : st)
        {
            ans.push_back(itr);
        }
        return ans;
    }
};