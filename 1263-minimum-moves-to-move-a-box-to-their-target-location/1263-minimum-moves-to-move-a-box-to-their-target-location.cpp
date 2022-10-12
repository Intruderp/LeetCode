class Solution {
public:
    int n,m;
    vector<int> dir{1,0,-1,0,1};
    int seen[20][20];
    bool valid(int &i,int j)
    {
        return i>=0 and j>=0 and i<n and j<m;
    }
    bool canReach(int &tx,int &ty,int curX,int curY,int &bx,int &by,vector<vector<char>> &grid)
    {
        if(!valid(curX,curY) or grid[curX][curY]=='#' or (curX==bx and curY==by) or seen[curX][curY])
            return false;
        seen[curX][curY]=1;
        if(curX==tx and curY==ty)
            return true;
        bool ans=false;
        for(int d=0;d<4;d++)
            ans|=canReach(tx,ty,curX+dir[d],curY+dir[d+1],bx,by,grid);
        return ans;
    }
    int minPushBox(vector<vector<char>>& grid) 
    {
        int level=0,tx,ty,px,py,x,y,bx,by,npx,npy;
        n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='T')
                    tx=i,ty=j;
                else if(grid[i][j]=='B')
                    bx=i,by=j;
                else if(grid[i][j]=='S')
                    px=i,py=j;
            }
        }
        queue<vector<int>> q;
        int vis[n][m][n][m];
        memset(vis,0,sizeof(vis));
        q.push({bx,by,px,py});
        vis[bx][by][px][py]=1;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto f=q.front();
                if(f[0]==tx and f[1]==ty)
                    return level;
                q.pop();
                for(int d=0;d<4;d++)
                {
                    x=f[0]+dir[d],y=f[1]+dir[d+1];
                    npx=f[0]+dir[d]*(-1),npy=f[1]+dir[d+1]*(-1);
                    memset(seen,0,sizeof(seen));
                    if(!valid(x,y) or !valid(npx,npy) or grid[x][y]=='#' or vis[x][y][npx][npy] or !canReach(npx,npy,f[2],f[3],f[0],f[1],grid))
                        continue;
                    vis[x][y][npx][npy]=1;
                    q.push({x,y,npx,npy});
                }
            }
            level++;
        }
        return -1;
    }
};