class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int k = -1;
        int flag = 0;
        if (n == 1)
        {
            return;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] >= nums[i + 1])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            int l = 0;
            int r = n - 1;
            while (l < r)
            {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }
        else
        {
            for (int i = n - 2; i >= 0; i--)
            {
                if (nums[i] < nums[i + 1])
                {
                    k = i;
                    break;
                }
            }
            cout << k << endl;
            for (int i = n - 1; i >= 0; i--)
            {
                if (nums[i] > nums[k])
                {

                    swap(nums[i], nums[k]);
                    break;
                }
            }
            cout << nums[0];
            int left = k + 1;
            int rt = n - 1;
            while (left < rt)
            {
                swap(nums[left], nums[rt]);
                left++;
                rt--;
            }
        }
    }
};