class BSTIterator
{
private:
    stack<TreeNode *> st;
    void psh(TreeNode *root)
    {
        while (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        psh(root);
    }

    int next()
    {
        TreeNode *nd = st.top();
        st.pop();
        psh(nd->right);
        return nd->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};
