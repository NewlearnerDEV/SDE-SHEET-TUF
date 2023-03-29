class Solution
{
public:
    static bool comp(Item x, Item y)
    {
        double ratio1 = (double)x.value / (double)x.weight;
        double ratio2 = (double)y.value / (double)y.weight;
        return ratio1 > ratio2;
        // sorted on basis of profit/weight ratio in non -ascending
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, comp);
        double tot = 0;
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (W > 0 && arr[i].weight <= W)
            {
                W = W - arr[i].weight;
                tot = tot + arr[i].value;

                k = i + 1;
            }
            else
            {
                break;
            }
        }
        if (W > 0 && k < n)
        {

            tot = tot + W * (arr[k].value * 1.0 / arr[k].weight);
        }

        return tot;
    }
};