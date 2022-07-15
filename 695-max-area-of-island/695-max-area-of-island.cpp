class Solution {
public:
    int sz=0,vis[50][50],n,m;
    void dfs(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0 or j<0 or i>=n or j>=m or vis[i][j] or grid[i][j]==0)
            return ;
        sz++;
        vis[i][j]=1;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j])
                {
                    sz=0;
                    dfs(i,j,grid);
                    ans=max(ans,sz);
                }
            }
        }
        return ans;
    }
};