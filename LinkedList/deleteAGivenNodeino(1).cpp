
node *getNode(node *head, int val)
{
    while (head->num != val)
        head = head->next;

    return head;
}
// get the deleting node pointer

void deleteNode(node *t)
{
    t->num = t->next->num;
    t->next = t->next->next;
    return;
}
// then deleting it