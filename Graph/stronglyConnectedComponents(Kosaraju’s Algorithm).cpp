#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], stack<int> &st,vector<int> & vis){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,st,vis);
        }
    }
    st.push(node);
}
void dfs2(int node,vector<int>& v, vector<int> adj[],vector<int> &vis){
    vis[node]=1;
    v.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs2(it,v,adj,vis);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    stack<int> st;
    vector<int> adj[n],t_adj[n];
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
    }
    vector<int> vis(n,0);
    //1.topo sort
    for(int i=0;i<n;++i){
        if(!vis[i]){
            dfs(i,adj,st,vis);
        }
    }

    //2.transpose
    for(int i=0;i<n;++i){
        vis[i]=0;
        for(auto it:adj[i]){
            t_adj[it].push_back(i);
        }
    }

    //3.dfs
    vector<vector<int>> ans;
    while(!st.empty()){
        int x=st.top();
        st.pop();
        if(!vis[x]){
            vector<int> v;
            dfs2(x,v,t_adj,vis);
            ans.push_back(v);
        }
    }
    return ans;
}
