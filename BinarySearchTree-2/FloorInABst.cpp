int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    TreeNode<int> *temp=root;
    int ans=-1;
    while(temp!=NULL)
    {
        if(temp->val==X)
        {
            return X;

        }
        else if(temp->val>X)
        {  
            
           
           
            temp=temp->left;
        }
        else
        {   
            
            ans=temp->val;
            
            temp=temp->right;
        }
    }
    return ans;
}