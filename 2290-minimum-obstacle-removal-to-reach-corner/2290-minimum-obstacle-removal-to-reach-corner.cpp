
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& g) 
    {
        int n=g.size(),m=g[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX)),dir{{1,0},{-1,0},{0,-1},{0,1}};
        dist[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});
        while(!q.empty())
        {
            int d=q.top().first;
            int x=q.top().second.first,y=q.top().second.second;
            q.pop();
            if(dist[x][y]<d)
                continue;
            for(auto &it:dir)
            {
                int a=x+it[0];
                int b=y+it[1];
                int e=0;
                if(a>=0 and b>=0 and a<n and b<m)
                {
                    if(g[a][b]==1)
                        e=1;
                    if(d+e<dist[a][b])
                    {
                        dist[a][b]=d+e;
                        q.push({dist[a][b],{a,b}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};