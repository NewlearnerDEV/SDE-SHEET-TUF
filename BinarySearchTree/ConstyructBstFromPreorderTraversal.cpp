class Solution
{
public:
    TreeNode *bst(int ele, TreeNode *rt)
    {
        if (rt == NULL)
        {
            return new TreeNode(ele);
        }

        if (rt->val > ele)
        {
            rt->left = bst(ele, rt->left);
        }
        else
        {
            rt->right = bst(ele, rt->right);
        }
        return rt;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int n = preorder.size();
        if (n == 0)
        {
            return NULL;
        }
        TreeNode *rt = new TreeNode(preorder[0]);

        for (int i = 1; i < n; i++)
        {
            bst(preorder[i], rt);
        }
        return rt;
    }
};