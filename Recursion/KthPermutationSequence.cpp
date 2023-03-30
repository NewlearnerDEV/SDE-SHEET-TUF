class Solution
{
public:
    int getfact(int n)
    {
        int fact = 1;
        for (int i = 1; i < n; i++) // 1 less means size of block
        {
            fact = fact * i;
        }
        return fact;
    }
    string getPermutation(int n, int k)
    {
        int fact = getfact(n);
        string ans = "";
        vector<int> num;
        for (int i = 1; i <= n; i++)
        {
            num.push_back(i);
        }
        k = k - 1; // 0-baxed indexing
        while (true)
        {
            ans = ans + to_string(num[k / fact]);
            num.erase(num.begin() + k / fact);
            if (num.size() == 0)
            {
                break;
            }
            k = k % fact;
            fact = fact / num.size(); // 4 num 6 in 1block the 2! erased 1 ele sizeis 3 nnow ie 6/3=2!
        }
        return ans;
    }
};