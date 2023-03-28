class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *count = head;
        int cnt = 0;
        ListNode *store = head;
        if (count == NULL)
        {
            return count;
        }
        while (count != NULL)
        {
            cnt++;
            count = count->next;
        }
        int mov = k % cnt;
        ListNode *temp = head;
        if (mov == 0)
        {
            return head;
        }
        for (int i = 1; i < cnt - mov; i++)
        {
            temp = temp->next;
        }
        ListNode *ans = temp->next;
        temp->next = NULL;
        temp = ans;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = store;

        return ans;
    }
};