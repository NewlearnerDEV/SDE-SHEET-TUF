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
    int cnt = 0;
    void rec(TreeNode *r, int t)
    {
        if (r == NULL)
        {
            cnt = max(cnt, t);
            return;
        }
        rec(r->left, t + 1);
        rec(r->right, t + 1);
    }
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        rec(root, 0);
        return cnt;
    }
};