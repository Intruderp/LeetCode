class Solution {
public:
    int n,m,mod=1e9+7;
    int help(int i,int j,int sum,int &k,vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if(i==n-1 and j==m-1)
            return (sum+grid[i][j])%k==0;
        if(i>=n or j>=m)
            return 0;
        if(dp[i][j][sum]!=-1)
            return dp[i][j][sum];
        return dp[i][j][sum]=(help(i+1,j,(sum+grid[i][j])%k,k,grid,dp)+help(i,j+1,(sum+grid[i][j])%k,k,grid,dp))%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k)
    {
        n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        return help(0,0,0,k,grid,dp);
    }
};