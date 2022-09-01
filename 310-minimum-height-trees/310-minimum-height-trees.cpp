class Solution {
public:
    int bfs(int src,int n,vector<int> adj[])
    {
        int res=0,maxD=-1;
        vector<int> dist(n,-1);
        queue<int> q;
        q.push(src);
        dist[src]=0;
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            for(auto &child:adj[f])
            {
                if(dist[child]==-1)
                {
                    dist[child]=dist[f]+1;
                    if(maxD<dist[child])
                    {
                        maxD=dist[child];
                        res=child;
                    }
                    q.push(child);
                }
            }
        }
        return res;
    }
    bool dfs(int start,int par,int end,vector<int> adj[],vector<int> &dia)
    {
        dia.push_back(start);
        if(start==end)
            return true;
        for(auto &child:adj[start])
        {
            if(child!=par)
            {
                if(dfs(child,start,end,adj,dia))
                    return true;
            }
        }
        dia.pop_back();
        return false;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        vector<int> adj[n];
        for(auto &edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int start=bfs(0,n,adj),end=bfs(start,n,adj);
        vector<int> dia;
        dfs(start,-1,end,adj,dia);
        n=dia.size();
        if(n%2)
            return {dia[n/2]};
        else 
            return {dia[n/2-1],dia[n/2]};
    }
};