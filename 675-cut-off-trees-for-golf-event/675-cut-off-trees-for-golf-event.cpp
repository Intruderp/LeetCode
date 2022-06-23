class Solution {
public:
    int n,m;
    vector<vector<int>> dir{{1,0},{-1,0},{0,-1},{0,1}};
    bool isValid(int x,int y)
    {
        return x>=0 and y>=0 and x<n and y<m;
    }
    int minDist(int x,int y,int a,int b,vector<vector<int>>& forest)
    {
        vector<vector<int>> dist(n,vector<int>(m,-1));
        if(forest[a][b]==0)
            return -1;
        dist[a][b]=0;
        queue<pair<int,int>> q;
        q.push({a,b});
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            if(t.first==x and t.second==y)
                return dist[x][y];
            for(auto &it:dir)
            {
                a=t.first+it[0];
                b=t.second+it[1];
                if(isValid(a,b) and forest[a][b]>0 and dist[a][b]==-1)
                {
                    dist[a][b]=dist[t.first][t.second]+1;
                    q.push({a,b});
                }
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) 
    {
        n=forest.size(),m=forest[0].size();
        vector<vector<int>> v;
        if(forest[0][0]==0)
            return -1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                if(forest[i][j]>1 or (i==0 and j==0))
                {
                    v.push_back({forest[i][j],i,j});
                }
            }
        }
        sort(v.begin(),v.end());
        int start=v[0][1],end=v[0][2],sz=v.size(),d,i=1,res=0;
        while(i<sz)
        {
            d=minDist(v[i][1],v[i][2],start,end,forest);
            if(d==-1)
                return d;
            res+=d;
            start=v[i][1];
            end=v[i][2];
            i++;
        }
        return res+minDist(v[0][1],v[0][2],0,0,forest);
    }
};