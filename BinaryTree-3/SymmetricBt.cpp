/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool rec(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == NULL && t2 == NULL)
        {
            return true;
        }
        if (t1 == NULL || t2 == NULL)
        {
            return false;
        }
        if (t1->val != t2->val)
        {
            return false;
        }
        return rec(t1->left, t2->right) && rec(t2->left, t1->right);
    }
    bool isSymmetric(TreeNode *root)
    {
        TreeNode *t1 = root;
        TreeNode *t2 = root;
        return rec(t1, t2);
    }
};