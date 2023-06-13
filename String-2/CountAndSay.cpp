class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        string ans = "";
        string prev = countAndSay(n - 1) + " ";
        char val = prev[0];
        int freq = 0;
        for (char ch : prev)
        {
            if (ch == val)
            {
                freq++;
            }
            else
            {

                ans = ans + to_string(freq) + val;
                freq = 1;
                val = ch;
            }
        }
        return ans;
    }
};