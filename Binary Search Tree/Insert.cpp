TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode* t=root;
        while(1){
            if(t->val<val){
                if(t->right==NULL){
                    t->right=new TreeNode(val);
                    break;
                }
                else{
                    t=t->right;
                }
            }
            else{
                 if(t->left==NULL){
                    t->left=new TreeNode(val);
                    break;
                }
                else{
                    t=t->left;
                }
            }
        }
        return root;

    }
