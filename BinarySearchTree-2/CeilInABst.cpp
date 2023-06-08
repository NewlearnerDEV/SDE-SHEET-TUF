int findCeil(BinaryTreeNode<int> *node, int x)
{
    // Write your code here.
    BinaryTreeNode<int> *temp = node;
    int ans = -1;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return x;
        }
        else if (temp->data > x)
        {

            ans = temp->data;

            temp = temp->left;
        }
        else
        {

            temp = temp->right;
        }
    }
    return ans;
}