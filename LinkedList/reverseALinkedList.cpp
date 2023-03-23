class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *temp = head;
        while (head != NULL)
        {
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
};