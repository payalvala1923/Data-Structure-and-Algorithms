vector<int> dp(1000001,-1);
long long mod=1e9+7;
int countDistinctWays(int nStairs) {
    if(nStairs<0) return 0;
    if(nStairs==0) return 1;
    if(dp[nStairs]!=-1) return dp[nStairs];
    return  dp[nStairs]= (countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2))%mod;
}
