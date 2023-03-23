class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int cnt = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }
        if (cnt == 0)
        {
            return NULL;
        }
        if (cnt == n)
        {
            return head->next;
        }
        int rem = cnt - n;
        ListNode *cur = head;
        ListNode *ch = head;
        int tmp = 0;
        ListNode *f = head;
        while (cur != NULL)
        {
            tmp++;
            if (tmp == rem)
            {
                f = f->next;
                cur->next = f->next;
            }
            cur = cur->next;
            f = cur;
        }
        return ch;
    }
};