#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int Max(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        return root->data;
    }
    int lt = Max(root->left);
    int rt = Max(root->right);
    return max(max(lt, rt), root->data);
}
int ct(BinaryTreeNode<int> *root, int max)
{
    if (!root)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        root->data = max;
        return max;
    }
    int lt = ct(root->left, max);
    int rt = ct(root->right, max);
    root->data = lt + rt;
    return root->data;
}
void changeTree(BinaryTreeNode<int> *root)
{
    // Write your code here.
    int maxi = Max(root);
    ct(root, maxi);
}