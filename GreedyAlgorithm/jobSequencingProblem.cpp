class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    static bool comp(Job x, Job y)
    {
        return x.profit > y.profit; // sort acc to profit in non-ascending..
    }
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, comp);
        vector<int> ans;

        int cmpdeadline = INT_MIN;
        int cnt = 0;
        int totprofit = 0;
        for (int i = 0; i < n; i++)
        {
            cmpdeadline = max(cmpdeadline, arr[i].dead);
        }
        vector<int> slots(cmpdeadline + 1, -1);

        for (int i = 0; i < n; i++)
        {
            for (int k = arr[i].dead; k > 0; k--)
            {
                if (slots[k] == -1)
                {
                    cnt++;
                    totprofit += arr[i].profit;
                    slots[k] = arr[i].id;
                    break;
                }
            }
        }
        ans.push_back(cnt);
        ans.push_back(totprofit);
        return ans;
    }
};