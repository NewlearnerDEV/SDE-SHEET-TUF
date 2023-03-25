class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
        {
            return false;
        }
        ListNode *ptr1 = head;
        ListNode *ptr2 = head;
        while (ptr2->next && ptr2->next->next)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            if (ptr1 == ptr2)
            {
                return true;
            }
        }

        return false;
    }
};