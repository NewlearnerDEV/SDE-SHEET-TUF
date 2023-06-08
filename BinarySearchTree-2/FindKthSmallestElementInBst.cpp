class Solution
{
public:
    int ans;
    void small(TreeNode *root, int k, int &i)
    {
        if (root == NULL)
        {
            return;
        }
        small(root->left, k, i);
        i++;
        if (i == k)
        {
            ans = root->val;
            return;
        }
        small(root->right, k, i);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int i = 0;
        small(root, k, i);
        return ans;
    }
};