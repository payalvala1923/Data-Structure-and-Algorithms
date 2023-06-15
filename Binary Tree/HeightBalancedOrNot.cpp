 int fun(TreeNode* root){
         
         if(root==NULL) return 0;
         int lh=fun(root->left);
         int rh=fun(root->right);
          if(lh==-1 || rh==-1 ) return -1;
         if(abs(lh-rh)>1) return -1;
         return 1+max(lh,rh);
         
         
     }
    bool isBalanced(TreeNode* root) {
       if (root == NULL)  return true;
       
		if (fun(root) == -1)  return false;
		return true;
        
    }
