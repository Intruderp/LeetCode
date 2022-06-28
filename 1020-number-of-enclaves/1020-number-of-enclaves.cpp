class Solution {
private:
    int count=0,n,m;
    bool poss;
    int vis[500][500];
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    bool isBoundaryCell(int i,int j){
        return i==0 or j==0 or i==n-1 or j==m-1;
    }
    bool isValid(int i,int j){
        return i>=0 and j>=0 and i<n and j<m;
    }
    void dfs(int i,int j,vector<vector<int>> &grid)
    {
        if(!isValid(i,j) or grid[i][j]==0 or vis[i][j])
            return ;
        count++;
        vis[i][j]=1;
        if(isBoundaryCell(i,j))
            poss=false;
        for(auto &d:dir)
        {
            int x=i+d[0],y=j+d[1];
            dfs(x,y,grid);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0)
                {
                    count=0;
                    poss=true;
                    dfs(i,j,grid);
                    if(poss)
                        res+=count;
                }
            }
        }
        return res;
    }
};