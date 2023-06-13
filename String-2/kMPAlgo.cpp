class Solution
{
public:
    int strStr(string s, string tar)
    {
        // int len=needle.length();
        // for(int i=0;i<haystack.length();i++)
        // {
        //     if(haystack.substr(i,len)==needle)
        //     {
        //         return i;
        //     }
        // }
        // return -1;
        // using kmp;
        int sln = s.size(), tln = tar.size();

        // creating LPS (longest prefix-suffix)
        vector<int> lps(tln, 0);
        int prevInd = 0, i = 1, j;
        while (i < tln)
        {
            if (tar[i] == tar[prevInd])
            {
                lps[i] = prevInd + 1;
                prevInd++;
                i++;
            }
            else
            {
                if (prevInd == 0)
                {
                    lps[i] = 0;
                    i++;
                }
                else
                    prevInd = lps[prevInd - 1];
            }
        }

        // actual KMP algorithm
        i = 0, j = 0; // i for s, j for tar
        while (i < sln)
        {
            if (s[i] == tar[j])
            {
                i++;
                j++;
            }
            else
            {
                if (j == 0)
                    i++;
                else
                    j = lps[j - 1];
            }

            if (j == tln)
                return (i - tln);
        }

        return -1;
    }
};