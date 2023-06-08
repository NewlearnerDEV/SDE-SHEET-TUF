class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
        {
            return "";
        }
        string s = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            if (cur == NULL)
            {
                s.append("#,");
            }
            else
            {
                s.append(to_string(cur->val) + ',');
            }
            if (cur != NULL)
            {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
        {
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *nd = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == "#")
            {
                nd->left = NULL;
            }
            else
            {
                TreeNode *lnd = new TreeNode(stoi(str));
                nd->left = lnd;
                q.push(lnd);
            }
            getline(s, str, ',');
            if (str == "#")
            {
                nd->right = NULL;
            }
            else
            {
                TreeNode *rnd = new TreeNode(stoi(str));
                nd->right = rnd;
                q.push(rnd);
            }
        }
        return root;
    }
};