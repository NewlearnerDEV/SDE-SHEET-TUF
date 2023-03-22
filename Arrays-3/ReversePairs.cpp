class Solution
{
    void merge(vector<int> &nums, int low, int mid, int high, int &cnt)
    {
        int leftInd = low, rightInd = mid + 1, r = rightInd, temp[high - low + 1], ind = 0, counter = 0;

        while (leftInd <= mid)
        {
            while (r <= high && (nums[leftInd] > (long)2 * nums[r]))
                counter++, r++;
            cnt += counter;
            while (rightInd <= high && nums[rightInd] <= nums[leftInd])
            {
                temp[ind++] = nums[rightInd++];
            }
            temp[ind++] = nums[leftInd++];
        }
        while (rightInd <= high)
        {
            temp[ind++] = nums[rightInd++];
        }
        for (int i = 0; i < ind; i++)
        {
            nums[low++] = temp[i];
        }
    }

    void mergesort(vector<int> &nums, int low, int high, int &cnt)
    {
        if (low < high)
        {
            int mid = low + (high - low) / 2;
            mergesort(nums, low, mid, cnt);
            mergesort(nums, mid + 1, high, cnt);
            merge(nums, low, mid, high, cnt);
        }
    }

public:
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
        {
            return 0;
        }
        int cnt = 0;
        mergesort(nums, 0, n - 1, cnt);
        return cnt;
    }
};