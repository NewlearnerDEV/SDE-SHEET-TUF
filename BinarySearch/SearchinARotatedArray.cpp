class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int start = 0;
        int n = nums.size();
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            int prev = (mid + n - 1) % n;
            int next = (mid + 1) % n;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] >= nums[start])
            {
                if (nums[mid] >= target && nums[start] <= target)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
                if (nums[mid] <= target && nums[end] >= target)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};