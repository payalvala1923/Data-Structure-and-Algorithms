 bool check(TreeNode* p, TreeNode* q){
        if(p==NULL || q==NULL) return p==q;
        if(p->val!=q->val) return false;
        return check(p->left,q->left)&&check(p->right,q->right);
   }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p,q);
        
    }
