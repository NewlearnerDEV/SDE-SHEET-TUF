int cntsmallthanmid(vector<int> &row, int mid)
{
    int low = 0;
    int high = row.size() - 1;
    while (low <= high)
    {
        int mid2 = low + (high - low) / 2;
        if (row[mid2] <= mid)
        {
            low = mid2 + 1;
        }
        else
        {
            high = mid2 - 1;
        }
    }
    return low;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 1;
    int high = 1e9;
    int x = (n * m) / 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            cnt += cntsmallthanmid(matrix[i], mid);
        }
        if (cnt <= x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}