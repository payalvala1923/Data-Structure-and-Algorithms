 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        int c=0;
        queue<TreeNode*> q;
        q.push(root);
        if(root==NULL)
        {
return v;}
        while(!q.empty())
        {
            int size=q.size();
            c++;
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
            if(c%2==0) reverse(data.begin(),data.end());
            v.push_back(data);
        }
        return v;
        
    }
