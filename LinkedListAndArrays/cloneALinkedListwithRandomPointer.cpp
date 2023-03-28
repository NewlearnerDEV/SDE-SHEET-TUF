class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *temp = head;
        Node *mv = head;
        Node *itr1 = head;
        Node *ans = new Node(0);
        Node *cur = ans;
        Node *itr2 = head;
        Node *front = head;
        while (temp != NULL)
        {
            mv = temp->next;
            Node *newNode = new Node(temp->val);
            temp->next = newNode;
            newNode->next = mv;
            temp = mv;
        }
        while (itr1 != NULL)
        {
            if (itr1->random != NULL)
            {
                itr1->next->random = itr1->random->next;
            }
            itr1 = itr1->next->next;
        }
        while (itr2 != NULL)
        {
            front = itr2->next->next;
            cur->next = itr2->next;

            itr2->next = front;
            cur = cur->next;
            itr2 = itr2->next;
        }
        return ans->next;
    }
};