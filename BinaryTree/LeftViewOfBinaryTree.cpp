void rec(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    rec(root->left, level + 1, ans);
    rec(root->right, level + 1, ans);
}
vector<int> leftView(Node *root)
{
    vector<int> ans;
    rec(root, 0, ans);
    return ans;
}
