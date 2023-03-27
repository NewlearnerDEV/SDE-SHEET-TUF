class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1)
        {
            return head;
        }
        if (head == NULL)
        {
            return NULL;
        }
        ListNode *temp = new ListNode(0);
        ListNode *countr = head;
        int count = 0;
        while (countr != NULL)
        {
            countr = countr->next;
            count++;
        }
        temp->next = head;
        ListNode *cur = temp;
        ListNode *post = temp;
        ListNode *pre = temp;
        while (count >= k)
        {
            cur = pre->next;
            post = cur->next;
            for (int i = 1; i < k; i++)
            {
                cur->next = post->next;
                post->next = pre->next;
                pre->next = post;
                post = cur->next;
            }
            pre = cur;
            count = count - k;
        }
        return temp->next;
    } // best in linked list
};