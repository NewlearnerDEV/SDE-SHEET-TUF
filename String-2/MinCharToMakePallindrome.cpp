bool isPal(string str, int i, int j)
{
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int minCharsforPalindrome(string str1)
{
    // Write your code here.
    int n = str1.length();
    int start = 0;
    int end = n - 1;
    int res = 0;
    while (start < end)
    {
        if (str1[start] == str1[end])
        {
            start++;
            end--;
        }
        else
        {
            res++;
            start = 0;
            end = n - res - 1;
        }
    }
    return res;
    // int cnt=0;int flag=0;
    // while(str.length()>0)
    // {
    // 	if(isPal(str,0,str.length()-1))
    // 	{
    //         flag=1;
    // 		break;
    // 	}
    // 	else{
    // 		cnt++;
    // 		str.erase(str.begin()+str.length()-1);
    // 	}
    // }
    // return cnt;
}