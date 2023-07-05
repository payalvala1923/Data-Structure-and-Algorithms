bool isValid(int c, bool graph[101][101],int node, int n, vector<int> color){
        for(int i=0;i<n;++i){
            if(graph[node][i]){
                if(color[i]==c) return false;
            }
        }
        return true;
    }
    bool solve(int node,bool graph[101][101] , int n , int m , vector<int> color){
        if(node==n) return true;
        
        for(int i=1;i<=m ;++i){
            
            if(isValid(i,graph, node, n, color) == true){
                color[node]=i;
                if(solve(node+1, graph,n,m,color)) return true;
                color[node]=0;
            }
            
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n,0);
        if(solve(0, graph, n, m, color)) return true;
        return false;
    }
