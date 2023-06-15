vector<vector<int>> verticalTraversal(TreeNode* root) {
        // node  v,l
        queue<pair<TreeNode*,pair<int, int>>> q;
        vector<vector<int>> ans;
        //v   l, nodes
        map<int,map<int, multiset<int>>> mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto t1=q.front();
            q.pop();
            TreeNode* t=t1.first;
            int v=t1.second.first;
            int l=t1.second.second;
            mp[v][l].insert(t->val);

            if(t->left){
                q.push({t->left,{v-1,l+1}});
            }
            if(t->right){
                q.push({t->right,{v+1,l+1}});
            }
        }
        for(auto i:mp){
            vector<int> col;
            for(auto p:i.second){
                col.insert(col.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(col);
        }
        return ans;  
    }
