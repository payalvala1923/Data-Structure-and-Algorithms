private:
   
    bool issafe(int x,int y,int n,vector<vector<int>> visited,vector<vector<int>> &m){
        if((x>=0&&x<n) &&(y>=0&&y<n) && (visited[x][y]==0)&&(m[x][y]==1))
            return true;
        return false;
    }
   
    void solve(vector<vector<int>> &m, int n, vector<string> &ans,string output,vector<vector<int>>visited,int x,int y){
        //base case;
        if(x==n-1 && y==n-1){
            ans.push_back(output);
            return ;
        }
        visited[x][y]=1;
        // down 
        int newx=x+1;
        int newy=y;
        if(issafe(newx,newy,n,visited,m)){
            output.push_back('D');
            solve(m,n,ans,output,visited,newx,newy);
            output.pop_back();
        }
        // left
          newx=x;
         newy=y-1;
        if(issafe(newx,newy,n,visited,m)){
            output.push_back('L');
              solve(m,n,ans,output,visited,newx,newy);
              output.pop_back();
        }
        // right
          newx=x;
         newy=y+1;
        if(issafe(newx,newy,n,visited,m)){
            output.push_back('R');
              solve(m,n,ans,output,visited,newx,newy);
              output.pop_back();
        }
        //up
         newx=x-1;
         newy=y;
        if(issafe(newx,newy,n,visited,m)){
            output.push_back('U');
              solve(m,n,ans,output,visited,newx,newy);
              output.pop_back();
        }
        visited[x][y]=0;
    }


    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
         
        vector<string>ans;
        
        if(m[0][0]==0){
            return ans;
        }
        string output="";
        vector<vector<int>> visited=m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        int sx=0; 
        int sy=0; 
        solve(m,n,ans,output,visited,sx,sy);
        
        return ans;
    }
