class Solution
{
public:
    void findInorder(TreeNode *temp, int k, vector<int> &l)
    {
        if (temp == NULL)
        {
            return;
        }
        findInorder(temp->left, k, l);
        l.push_back(temp->val);
        findInorder(temp->right, k, l);
    }
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> ord;
        TreeNode *temp = root;
        findInorder(temp, k, ord);
        int i = 0;
        int j = ord.size() - 1;
        while (i < j)
        {
            if (ord[i] + ord[j] == k)
            {
                return true;
            }
            else if (ord[i] + ord[j] > k)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};