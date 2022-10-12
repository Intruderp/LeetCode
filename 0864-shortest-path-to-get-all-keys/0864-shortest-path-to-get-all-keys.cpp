class Solution {
public:
    int n,m;
    vector<int> dir{1,0,-1,0,1};
    bool valid(int &i,int &j)
    {
        return i>=0 and i<n and j>=0 and j<m;
    }
    int shortestPathAllKeys(vector<string>& grid) 
    {
        n=grid.size(),m=grid[0].size();
        int level=0,key=0,x,y;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='@')
                    x=i,y=j;
                else if(grid[i][j]>='a' and grid[i][j]<='f')
                    key++;
            }
        }
        vector<vector<vector<int>>> vis(n,vector<vector<int>>(m,vector<int>((1<<key),0)));
        queue<vector<int>> q;
        q.push({x,y,0});
        vis[x][y][0]=1;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto f=q.front();
                q.pop();
                for(int d=0;d<4;d++)
                {
                    x=f[0]+dir[d],y=f[1]+dir[d+1];
                    if(!valid(x,y) or grid[x][y]=='#')
                        continue;
                    if(grid[x][y]>='A' and grid[x][y]<='F' and (f[2]&(1<<(grid[x][y]-'A')))==0)
                        continue;
                    int newMask=f[2];
                    if(grid[x][y]>='a' and grid[x][y]<='f')
                        newMask|=(1<<(grid[x][y]-'a'));
                    if(newMask==((1<<key)-1))
                       return level+1;
                    if(vis[x][y][newMask]==0)
                    {
                        q.push({x,y,newMask});
                        vis[x][y][newMask]=1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};