class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
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
            if (mp.find(vl) == mp.end())
            {
                mp[vl] = nd->data;
            }

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