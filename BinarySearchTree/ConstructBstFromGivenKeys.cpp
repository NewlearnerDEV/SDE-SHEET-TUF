class Solution
{
public:
    TreeNode *createTree(int i, int j, vector<int> &nums)
    {
        if (i > j)
        {
            return NULL;
        }
        int mid = (i + j) / 2;
        TreeNode *rt = new TreeNode(nums[mid]);

        rt->left = createTree(i, mid - 1, nums);
        rt->right = createTree(mid + 1, j, nums);
        return rt;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int i = 0;
        int n = nums.size();
        return createTree(i, n - 1, nums);
    }
};