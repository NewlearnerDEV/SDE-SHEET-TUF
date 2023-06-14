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
    TreeNode *ctree(vector<int> &pre, vector<int> &ino, int is, int ps, int ie, int pe, map<int, int> &mp)
    {
        if (ps > pe || is > ie)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(pre[ps]);
        int el = mp[root->val];
        int dist = el - is;
        root->left = ctree(pre, ino, is, ps + 1, el - 1, ps + dist, mp);
        root->right = ctree(pre, ino, el + 1, ps + dist + 1, ie, pe, mp);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int is = 0, ps = 0, ie = inorder.size() - 1, pe = preorder.size() - 1;
        map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return ctree(preorder, inorder, is, ps, ie, pe, mp);
    }
};