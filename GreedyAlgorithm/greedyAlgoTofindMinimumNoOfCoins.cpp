#include <bits/stdc++.h>
int findMinimumCoins(int amount)
{
    int cnt = 0;
    int arr[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int n = 9;
    for (int i = 0; i < n; i++)
    {
        if (amount == 0)
        {
            break;
        }
        if (amount / arr[i] >= 1)
        {
            cnt += amount / arr[i];
            amount = amount - cnt * arr[i];
        }
    }
    return count;
}