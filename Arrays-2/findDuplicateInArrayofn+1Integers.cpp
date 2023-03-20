class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size() - 1;
        int ans;
        // brute-force
        // for(int i=1;i<=n;i++)
        // {
        //      int cnt=0;
        //      for(int j=0;j<nums.size();j++)
        //      {
        //           if(i==nums[j])
        //           {
        //               cnt++;
        //           }
        //      }
        //      if(cnt!=1&&cnt!=0)
        //      {
        //          ans=i;
        //          break;
        //      }
        // }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i])] > 0)
            {
                nums[abs(nums[i])] = -nums[abs(nums[i])];
            }
            else
            {
                return abs(nums[i]);
            }
        }

        return 0;
    }
};