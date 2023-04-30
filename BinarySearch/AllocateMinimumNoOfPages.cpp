
bool allocated(vector<int> &A, int B, int mid)
{
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (sum + A[i] > mid)
        {
            cnt++;
            sum = A[i];
            if (sum > mid)
            {
                return false;
            }
        }
        else
        {
            sum += A[i];
        }
    }
    if (cnt < B)
    {
        return true;
    }
    return false;
}

int Solution::books(vector<int> &A, int B)
{
    int n = A.size();
    int low = A[0];
    int high = 0;
    for (int i = 0; i < n; i++)
    {
        high += A[i];
        low = min(low, A[i]);
    }
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (allocated(A, B, mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
