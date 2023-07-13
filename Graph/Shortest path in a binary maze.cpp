int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       int m = grid.size(),n = grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> visited(m,vector<int>(n,0));
        if(grid[0][0] == 1) return -1;
        q.push({0,{0,1}});
        int ans = INT_MAX;
        visited[0][0] = 1;
        while(!q.empty()){
            int r = q.front().first,c = q.front().second.first,takentime = q.front().second.second;
            q.pop();
            if(r == m-1 && c==n-1){
                ans = min(ans,takentime);
                continue;
            }
            for(int i=-1;i<=1;i++){
                for(int z=-1;z<=1;z++){
                    int row = r+z,col = c+i;
                    if(row == r && col == c) continue;
                    else if(row >=0 && row < m && col >= 0 && col<n && grid[row][col] == 0 && !visited[row][col] ){
                         visited[row][col] =1;
                        q.push({row,{col,takentime+1}});
                    }
                }
            }
        }
        return ans == INT_MAX?-1:ans;
    }








#include <bits/stdc++.h>
using namespace std;
int shortestPathBinaryMatrix(vector<vector<int>> &matrix, pair<int, int> src, pair<int, int> dest)
{
      if (src.first == dest.first && src.second == dest.second)
            return 0;

        queue< pair <int, pair<int, int> > > q;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[src.first][src.second] = 0;
        q.push({0, {src.first, src.second}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

          
            for (int i = 0; i < 4; i++)
            {
                int newr = r + dr[i];
                int newc = c + dc[i];

              
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && matrix[newr][newc]  == 1 && dis + 1 < dist[newr][newc])
                {
                    dist[newr][newc] = 1 + dis;
                    if(newr==dest.first && newc==dest.second){

                        return dis+1;

                    }
                    q.push({1 + dis, {newr, newc}});
                }
            }
        }
        return -1;
}
