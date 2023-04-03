class Solution
{

public:
    float mul(int a, int b, int c)
    {
        float res = 1;
        for (int i = 1; i <= b; i++)
        {
            res = res * a;
            if (res > c)
            {
                break;
            }
        }
        return res;
    }
    int NthRoot(int n, int m)
    {
        int start = 1;
        int end = m;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            float x = mul(mid, n, m);
            if (x == m)
            {
                return mid;
            }
            else if (x > m)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
};