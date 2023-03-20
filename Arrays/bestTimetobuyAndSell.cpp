class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int fst = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            int diff = prices[i] - fst;
            profit = max(profit, diff);
            fst = min(fst, prices[i]);
        }
        return profit;
    }
};