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
    TreeNode *ctree(vector<int> &pre, vector<int> &ino, int is, int ps, int ie, int pe, map<int, int> &mp, int n)
    {
        if (ps > pe || is > ie)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(pre[pe]);
        int el = mp[root->val];
        int dist = el - is;
        root->left = ctree(pre, ino, is, ps, el - 1, ps + dist - 1, mp, n);
        root->right = ctree(pre, ino, el + 1, ps + dist, ie, pe - 1, mp, n);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int is = 0, ps = 0, ie = inorder.size() - 1, pe = postorder.size() - 1;
        int n = inorder.size();

        map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return ctree(postorder, inorder, is, ps, ie, pe, mp, n);
    }
};