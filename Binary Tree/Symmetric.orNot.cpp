  bool check(TreeNode* p, TreeNode* q){
        if(p==NULL || q==NULL) return p==q;
        if(p->val!=q->val) return false;
        return check(p->left,q->right)&&check(p->right,q->left);
   }
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
        
        
    }
