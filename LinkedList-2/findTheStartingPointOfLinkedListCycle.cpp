class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *ptr1 = head;
        ListNode *coll = NULL;
        ListNode *ptr2 = head;
        int flag = 0;
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        while (ptr2->next && ptr2->next->next)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            if (ptr1 == ptr2)
            {
                coll = ptr1;
                flag = 1;
                break;
            }
        }
        ListNode *ent = head;
        if (flag == 1)
        {
            while (ent != coll)
            {

                ent = ent->next;
                coll = coll->next;
            }
            return ent;
        }
        else
        {
            return NULL;
        }
    }
};