class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *crt = new ListNode();
        ListNode *temp = crt;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry == 1)
        {
            int sum = 0;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            int ans = (sum + carry) % 10;
            // cout<<ans;
            carry = (sum + carry) / 10;
            // cout<<carry;

            ListNode *dmp = new ListNode(ans);
            temp->next = dmp;
            temp = temp->next;
        }
        return crt->next;
    }
};

//java soln  did earlier

class Solution
{
public
    ListNode addTwoNumbers(ListNode l1, ListNode l2)
    {
        ListNode ans = new ListNode();
        int carry = 0;
        ListNode start = ans;
        while (l1 != null || l2 != null)
        {
            if (l1 != null && l2 != null)
            {
                ans.val = l1.val + l2.val + carry;
            }
            if (l1 != null && l2 == null)
            {
                ans.val = l1.val + carry;
            }
            if (l1 == null && l2 != null)
            {
                ans.val = l2.val + carry;
            }

            if (l1 != null)
            {
                l1 = l1.next;
            }
            if (l2 != null)
            {
                l2 = l2.next;
            }
            if (ans.val > 9)
            {
                ans.val = ans.val % 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            if (l1 != null || l2 != null)
            {
                ans.next = new ListNode();
                ans = ans.next;
            }
        }
        if (carry == 1)
        {
            ans.next = new ListNode(1);
        }
        return start;
    }
}
