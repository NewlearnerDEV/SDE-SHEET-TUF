class Solution
{
public:
    bool check(TreeNode *root, long mn, long mx)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->val >= mx || root->val <= mn)
        {
            return false;
        }
        return check(root->left, mn, root->val) && check(root->right, root->val, mx);
    }
    bool isValidBST(TreeNode *root)
    {

        return check(root, LONG_MIN, LONG_MAX);
    }
};