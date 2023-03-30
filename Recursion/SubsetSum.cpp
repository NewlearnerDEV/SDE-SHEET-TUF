class Solution
{
public:
    void subset(vector<int> &arr, int n, vector<int> &ans, int sum)
    {
        if (n == 0)
        {
            ans.push_back(sum);
            return;
        }

        subset(arr, n - 1, ans, sum + arr[n - 1]);

        subset(arr, n - 1, ans, sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        subset(arr, N, ans, 0);
        return ans;
    }
};