class Solution{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);
        int mn = 1;
        int cnt = 1;
        int j = 0;
        for (int i = 1; i < n;)
        {
            if (j >= n)
            {
                break;
            }
            if (arr[i] <= dep[j])
            {
                cnt++;
                i++;
            }
            else
            {
                cnt--;
                j++;
            }
            mn = max(cnt, mn);
        }
        return mn;
    }
};