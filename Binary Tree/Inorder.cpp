vector<int> v;
    void solve(TreeNode* root)
    {
        if(root==NULL) return;
        solve(root->left);
        v.push_back(root->val);
        solve(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        return v;
        
    }
