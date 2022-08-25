class Solution {
public:
    vector<int> dir{1,0,-1,0,1};
    int n,m,x,y;
    bool isValid(int i,int j)
    {
        return i>=0 and j>=0 and i<n and j<m;
    }
    bool canReach(int &max,vector<vector<int>>& dist,vector<vector<int>>& grid)
    {
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> d(n,vector<int>(m,-1));
        d[0][0]=0;
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                x=f.first+dir[i];
                y=f.second+dir[i+1];
                if(isValid(x,y) and grid[x][y]!=2 and d[x][y]==-1)
                {
                    d[x][y]=d[f.first][f.second]+1;
                    if(dist[x][y]>max+d[x][y])
                    {
                        q.push({x,y});
                        if(x==n-1 and y==m-1)
                            return true;
                    }
                    else if(x==n-1 and y==m-1 and dist[x][y]>=max+d[x][y])
                        return true;
                }
            }
        }
        return false;
    }
    int maximumMinutes(vector<vector<int>>& grid) 
    {
        n=grid.size(),m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                x=f.first+dir[i];
                y=f.second+dir[i+1];
                if(isValid(x,y) and grid[x][y]!=2 and dist[x][y]==INT_MAX)
                {
                    dist[x][y]=1+dist[f.first][f.second];
                    q.push({x,y});
                }
            }
        }
        int low=0,high=1e9,mid,res=-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(canReach(mid,dist,grid))
            {
                res=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return res;
    }
};