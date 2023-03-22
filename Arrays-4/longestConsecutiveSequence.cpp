class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> st;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {

            st.insert(nums[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (st.find(nums[i] - 1) == st.end()) // we dont get ie the cur nums[i] is minimal
            {
                int k = nums[i];
                int cnt = 0;
                while (st.find(k + 1) != st.end())
                {
                    cnt++;
                    k = k + 1;
                }
                ans = max(ans, cnt + 1);
            }
        }

        return ans;
    }
};