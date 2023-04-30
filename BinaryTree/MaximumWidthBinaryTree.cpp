class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {

        if (!root)
        {
            return 0;
        }
        int ans = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto pr = q.front();
            TreeNode *nd = pr.first;
            int mnm = pr.second;
            int fst, last;

            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                auto pr2 = q.front();
                TreeNode *rt = pr2.first;
                int lev = pr2.second - mnm;
                q.pop();
                if (i == 0)
                {
                    fst = lev;
                }
                if (i == n - 1)
                {
                    last = lev;
                }
                if (rt->left != NULL)
                {
                    q.push({rt->left, (long long)2 * lev + 1});
                }
                if (rt->right != NULL)
                {
                    q.push({rt->right, (long long)2 * lev + 2});
                }
            }
            ans = max(ans, last - fst + 1);
        }
        return ans;
    }
};