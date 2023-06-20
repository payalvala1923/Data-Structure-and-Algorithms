void ceil(BinaryTreeNode<int> *node, int x, int &ans){
    if(node==NULL) return;
    if(node->data==x){
        ans=x;
        return;
    }
    else if(node->data<x){
        ceil(node->right,x,ans);
    }
    else{
        ans=node->data;
        ceil(node->left,x,ans);
    }
}
int findCeil(BinaryTreeNode<int> *node, int x){
    int ans=-1;
    ceil(node,x,ans);
    return ans;
}
