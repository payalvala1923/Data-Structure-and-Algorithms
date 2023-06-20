private:
    TreeNode *findLastChild(TreeNode* root){
        if(root->right==NULL) return root;
        return findLastChild(root->right);
    }
    TreeNode *helper(TreeNode *root){
        if(root->left==NULL) return root->right;
        if(root->right==NULL) return root->left;
        TreeNode* rightchild=root->right;
        TreeNode* lastchild=findLastChild(root->left);
        lastchild->right=rightchild;
        return root->left;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        int X=key;
    if(root==NULL) return root;
    if(root->val==X) return helper(root);
    TreeNode* t=root;
    while(t!=NULL){
            if(t->val<X){
                if(t->right!=NULL && t->right->val==X ){
                    t->right=helper(t->right);
                    break;
                }
                else{
                    t=t->right;
                }
            }
            else{
                if(t->left!=NULL && t->left->val==X){
                    t->left=helper(t->left);
                    break;
                    
                }
                else{
                    t=t->left;
                }
            }

   }
   return root;
    }
