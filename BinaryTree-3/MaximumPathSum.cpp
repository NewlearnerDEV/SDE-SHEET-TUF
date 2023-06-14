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
    int rec(TreeNode *root, int &maxi)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lt = max(0, rec(root->left, maxi));
        int rt = max(0, rec(root->right, maxi));
        int value = root->val;
        maxi = max(maxi, (value + lt + rt));
        return max(lt, rt) + value;
    }
    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        rec(root, maxi);
        return maxi;
    }
};