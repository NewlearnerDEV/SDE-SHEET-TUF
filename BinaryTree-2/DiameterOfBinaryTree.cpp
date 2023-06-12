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
    int rec(TreeNode *rt, int &dia)
    {
        if (!rt)
        {
            return 0;
        }
        int lh = rec(rt->left, dia);
        int rh = rec(rt->right, dia);

        dia = max(dia, lh + rh);

        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int d = 0;
        rec(root, d);
        return d;
    }
};