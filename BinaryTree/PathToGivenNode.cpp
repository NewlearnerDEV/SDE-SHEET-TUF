bool rec(TreeNode *A, int B, vector<int> &ans)
{
    if (root == NULL)
    {
        return false;
    }
    ans.push_back(A->val);

    if (A->val == B)
    {
        return true;
    }
    if (rec(A->left, B, ans) || rec(A->right, B, ans))
    {

        return true;
    }
    ans.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode *A, int B)
{
    vector<int> ans;
    bool check = rec(A, B, ans);
    return ans;
}