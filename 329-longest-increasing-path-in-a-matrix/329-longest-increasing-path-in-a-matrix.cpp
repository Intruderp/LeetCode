class Solution {
public:
    int n,m,dp[200][200];
    int dfs(int i,int j,int p,vector<vector<int>>& matrix)
    {
        if(i<0 or j<0 or i>=n or j>=m or matrix[i][j]<=p)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=max({dfs(i+1,j,matrix[i][j],matrix),dfs(i-1,j,matrix[i][j],matrix),dfs(i,j-1,matrix[i][j],matrix),dfs(i,j+1,matrix[i][j],matrix)})+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int ans=0;
        n=matrix.size();
        m=matrix[0].size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                ans=max(ans,dfs(i,j,-1,matrix));
        }
        return ans;
    }
};