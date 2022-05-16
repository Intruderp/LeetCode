class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        if(grid[0][0])
            return -1;
        int n=grid.size(),m=grid[0].size();
        if(n==1)
            return 1;
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
        int x,y,sz,steps=1;
        while(!q.empty())
        {
            steps++;
            sz=q.size();
            while(sz--)
            {
                auto t=q.front();
                q.pop();
                for(auto &it:dir)
                {
                    x=t.first+it[0];
                    y=t.second+it[1];
                    if(x>=0 and y>=0 and x<n and y<m and grid[x][y]==0)
                    {
                        grid[x][y]=1;
                        q.push({x,y});
                        if(x==n-1 and y==m-1)
                            return steps;
                    }  
                }
            }
        }
        return -1;
    }
};