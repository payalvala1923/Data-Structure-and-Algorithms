 int pathsum(TreeNode* root,int &ans)
    {
        if(root==NULL) return 0;
        int left=max(0,pathsum(root->left,ans));
        int right=max(0,pathsum(root->right,ans));
        ans=max(ans,left+right+ root->val);
        return max(left,right)+ root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        pathsum(root,ans);
        return ans;

    }
