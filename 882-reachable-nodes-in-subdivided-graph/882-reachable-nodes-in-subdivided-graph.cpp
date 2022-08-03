class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) 
    {
        vector<pair<int,int>> adj[n];
        for(auto &edge:edges)
        {
            adj[edge[0]].push_back({edge[1],edge[2]+1});
            adj[edge[1]].push_back({edge[0],edge[2]+1});
        }
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,0});
        while(!q.empty())
        {
            auto t=q.top();
            q.pop();
            for(auto &edge:adj[t.second])
            {
                if(dist[edge.first]>t.first+edge.second)
                {
                    dist[edge.first]=t.first+edge.second;
                    q.push({dist[edge.first],edge.first});
                }
            }
        }
        int res=0,x;
        for(int i=0;i<n;i++)
            res+=dist[i]<=maxMoves;
        for(auto &edge:edges)
        {
            x=max(0,maxMoves-dist[edge[0]])+max(0,maxMoves-dist[edge[1]]);
            res+=min(x,edge[2]);
        }
        return res;
    }
};