class Solution
{
public:
    int ans;
    void large(Node *root, int K, int &i)
    {
        if (root == NULL)
        {
            return;
        }
        large(root->right, K, i);
        i++;
        if (i == K)
        {
            ans = root->data;
            return;
        }

        large(root->left, K, i);
    }
    int kthLargest(Node *root, int K)
    {
        int i = 0;
        large(root, K, i);
        return ans;
    }
};