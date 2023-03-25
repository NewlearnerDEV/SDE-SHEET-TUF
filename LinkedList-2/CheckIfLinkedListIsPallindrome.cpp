class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> vec;
        while (head != NULL)
        {
            vec.push_back(head->val);
            head = head->next;
        }
        int l = 0;
        int r = vec.size() - 1;
        while (l < r)
        {
            if (vec[l] != vec[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};

// to do in 0(1) space complexity find middle take reverse after middle
// then check in o(n)