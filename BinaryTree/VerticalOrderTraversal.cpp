class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;

        queue<pair<TreeNode *, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mp;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto itr = q.front();
            q.pop();
            TreeNode *nd = itr.first;
            int ver = itr.second.first;
            int hori = itr.second.second;
            mp[ver][hori].insert(nd->val);
            if (nd->left != NULL)
            {
                q.push({nd->left, {ver - 1, hori + 1}});
            }
            if (nd->right != NULL)
            {
                q.push({nd->right, {ver + 1, hori + 1}});
            }
        }

        for (auto itr : mp)
        {
            vector<int> temp;
            for (auto itr2 : itr.second)
            {
                temp.insert(temp.end(), itr2.second.begin(), itr2.second.end());
            }
            ans.push_back(temp);
        }

        return ans;
    }
};