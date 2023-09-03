class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int e, int f, vector<vector<int>> &dp){
        if(f==0 || f==1) return f;
        if(e==1) return f;
        int mn=INT_MAX;
         if(dp[e][f]!=-1){
            return dp[e][f]; 
        }
        for(int k=1;k<=f;++k){
            int temp=1+ max(solve(e-1,k-1, dp), solve(e, f-k, dp));
            mn=min(mn, temp);
        }
        return dp[e][f]=mn;
    }
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1, vector<int> (k+1,-1));
        
        return solve(n, k, dp);
    }
};
