class Solution
{
public:
    Node *connect(Node *root)
    {

        if (root == NULL)
        {
            return root;
        }
        queue<Node *> q;

        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            vector<Node *> ans;
            for (int i = 0; i < n; i++)
            {
                Node *fr = q.front();
                q.pop();
                if (fr->left != NULL)
                {
                    q.push(fr->left);
                }
                if (fr->right != NULL)
                {
                    q.push(fr->right);
                }
                ans.push_back(fr);
            }

            for (int i = 1; i < ans.size(); i++)
            {
                ans[i - 1]->next = ans[i];
            }
        }

        return root;
    }
};