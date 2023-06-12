class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        int k = 0;
        while (!q.empty())
        {
            int n = q.size();

            vector<int> temp;
            for (int i = 0; i < n; i++)
            {
                TreeNode *rt = q.front();

                temp.push_back(rt->val);
                q.pop();
                if (rt->left != NULL)
                {
                    q.push(rt->left);
                }
                if (rt->right != NULL)
                {
                    q.push(rt->right);
                }
            }
            if (k % 2 == 0)
            {
                ans.push_back(temp);
                k++;
            }
            else
            {
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                k++;
            }
        }
        return ans;
    }
};