class Solution {
public:
    int dir[5]={1,0,-1,0,1},n,m;
    bool valid(int &i,int &j)
    {
        return i>=0 and j>=0 and i<n and j<m;
    }
    void mark(int i,int j,int &cur,vector<vector<int>> &grid)
    {
        if(!valid(i,j) or grid[i][j]!=1)
            return ;
        grid[i][j]=cur;
        for(int d=0;d<4;d++)
        {
            mark(i+dir[d],j+dir[d+1],cur,grid);
        }
    }
    void dfs(int i,int j,int cur,bool &poss,vector<vector<int>> &grid,vector<vector<int>> &grid2)
    {
        if(!valid(i,j) or grid[i][j]==0)
            return ;
        if(grid2[i][j]!=cur)
        {
            poss=false;
        }
        grid[i][j]=0;
        for(int d=0;d<4;d++)
        {
            dfs(i+dir[d],j+dir[d+1],cur,poss,grid,grid2);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        int cur=2,cnt=0;
        n=grid1.size(),m=grid1[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid1[i][j]==1)
                {
                    mark(i,j,cur,grid1);
                    cur++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1 and grid1[i][j])
                {
                    bool poss=true;
                    dfs(i,j,grid1[i][j],poss,grid2,grid1);
                    cnt+=poss;
                }
            }
        }
        return cnt;
    }
};