void floor(TreeNode<int> *node, int x, int &ans){
    if(node==NULL) return;
    if(node->val==x){
        ans=x;
        return;
    }
    else if(node->val<x){
        ans=node->val;
        floor(node->right,x,ans);
    }
    else{
        floor(node->left,x,ans);
    }
}
int floorInBST(TreeNode<int> * root, int X)
{
    int ans=-1;
    floor(root,X,ans);
    return ans;
}
