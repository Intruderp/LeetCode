class Solution {
public:
    int c,n,m,vis[50][50];
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]!=c or vis[i][j])
            return ;
        vis[i][j]=1;
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
    bool isBoundaryCell(int i,int j)
    {
        return i==0 or j==0 or i==n-1 or j==m-1 or !vis[i+1][j] or !vis[i-1][j] or !vis[i][j-1] or !vis[i][j+1];
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        c=grid[row][col];
        n=grid.size();
        m=grid[0].size();
        dfs(grid,row,col);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j] and isBoundaryCell(i,j))
                    grid[i][j]=color;
                else if(vis[i][j])
                    grid[i][j]=c;
                    
            }
        }
        return grid;
    }
};