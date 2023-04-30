class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;
        map<int, int> mp;
        queue<pair<Node *, int>> q;
        q.push({root, 0}); // 0 means taken vertical line
        while (!q.empty())
        {
            auto itr = q.front();
            q.pop();
            Node *nd = itr.first;
            int vl = itr.second;
            mp[vl] = nd->data;

            if (nd->left != NULL)
            {
                q.push({nd->left, vl - 1});
            }

            if (nd->right != NULL)
            {
                q.push({nd->right, vl + 1});
            }
        }

        for (auto itr : mp)
        {
            ans.push_back(itr.second);
        }
        return ans;
    }
};