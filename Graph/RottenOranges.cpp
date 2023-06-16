//  You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int n=grid.size(),m=grid[0].size();
        int t=0;
        queue<pair<int, int>> q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] != 0) t++;
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int c=0,days=0;
        while(!q.empty()){
            int sz=q.size();
            c+=sz;
            while(sz--){
            int x=q.front().first,y=q.front().second;
            q.pop();
           
            int dx[4]={0,0,-1,1};
            int dy[4]={-1,1,0,0};
            
            for(int i=0;i<4;++i){
                int ix=dx[i]+x,iy=dy[i]+y;
                if(ix<0 || iy<0 || ix>=n || iy>=m || grid[ix][iy]!=1) continue;
                grid[ix][iy]=2;
                q.push({ix,iy});
            }
            }
            if(!q.empty()) ++days;
            
        }
        
        if(c==t) return days;
        return -1;
        
    }
