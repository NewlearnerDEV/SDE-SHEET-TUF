class NodeVal
{
public:
    bool isBst;
    int maxNode, minNode, maxSum;
    NodeVal()
    {

        isBst = true;
        minNode = INT_MAX;
        maxNode = INT_MIN;
        maxSum = 0;
    }
};
int ans;
class Solution
{
public:
    NodeVal FindSum(TreeNode *root)
    {
        if (root == NULL)
        {
            return NodeVal();
        }
        NodeVal curr;
        NodeVal lt = FindSum(root->left);
        NodeVal rt = FindSum(root->right);
        if ((lt.isBst == true && rt.isBst == true) && (lt.maxNode < root->val && root->val < rt.minNode))
        {
            curr.isBst = true;
            curr.maxSum = lt.maxSum + rt.maxSum + root->val;
            curr.minNode = min(lt.minNode, root->val);
            curr.maxNode = max(rt.maxNode, root->val);
        }
        else
        {
            curr.isBst = false;
            curr.maxSum = max(lt.maxSum, rt.maxSum);
        }
        ans = max(ans, curr.maxSum);
        return curr;
    }
    int maxSumBST(TreeNode *root)
    {
        ans = 0;
        NodeVal obj = FindSum(root);
        return ans;
    }
};