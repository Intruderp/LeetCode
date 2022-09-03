class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        int n=mat.size(),m=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        vector<int> dir{1,0,-1,0,1};
        while(!q.empty())
        {
            auto cell=q.front();
            q.pop();
            for(int d=0;d<4;d++)
            {
                int x=cell.first+dir[d],y=cell.second+dir[d+1];
                if(x>=0 and x<n and y>=0 and y<m and dist[x][y]==-1)
                {
                    dist[x][y]=1+dist[cell.first][cell.second];
                    q.push({x,y});
                }
            }
        }
        return dist;
    }
};