class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return root;
        }
        int data = root->val;
        if (data > p->val && data > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (data < p->val && data < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};