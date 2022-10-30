class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k)
    {
        int n=grid.size(),m=grid[0].size(),x,y;
        if(n==1 and m==1)
            return 0;
        vector<vector<int>> dist(n,vector<int>(m,-1)),dir{{1,0},{-1,0},{0,1},{0,-1}},vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        dist[0][0]=0;
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            for(auto &it:dir)
            {
                x=it[0]+f.second.first;
                y=it[1]+f.second.second;
                if(x>=0 and y>=0 and x<n and y<m and (dist[x][y]==-1 or vis[x][y]>f.first))
                {
                    dist[x][y]=dist[f.second.first][f.second.second]+1;
                   if(x==n-1 and y==m-1)
                       return dist[x][y];
                    vis[x][y]=f.first;
                    if(grid[x][y])
                    {
                        if(f.first<k)
                            q.push({f.first+1,{x,y}});
                    }
                    else
                        q.push({f.first,{x,y}});
                }
            }
        }
        return -1;
    }
};