class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int cnx = 0, cny = 0, cnz = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                cnx++;
            }
            if (nums[i] == 1)
            {
                cny++;
            }
            if (nums[i] == 2)
            {
                cnz++;
            }
        }
        int k = 0;

        while (cnx != 0)
        {
            nums[k] = 0;
            k++;
            cnx--;
        }
        while (cny != 0)
        {
            nums[k] = 1;
            k++;
            cny--;
        }
        while (cnz != 0)
        {
            nums[k] = 2;
            k++;
            cnz--;
        }
    }
};