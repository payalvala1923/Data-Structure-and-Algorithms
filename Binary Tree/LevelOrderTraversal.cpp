vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);
        if(root==NULL)
        {
return v;}
        while(1)
        {
            int size=q.size();
            if(size==0)
                return v;
            vector<int> data;
            while(size>0)
            {
                TreeNode* temp=q.front();
                q.pop();
                data.push_back(temp->val);
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
                size--;
            }
            v.push_back(data);
        }
        return v;
        
    }
