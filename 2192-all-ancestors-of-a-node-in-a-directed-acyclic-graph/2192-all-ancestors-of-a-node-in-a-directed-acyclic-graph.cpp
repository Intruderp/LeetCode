class Solution {
public:
    vector<vector<int>> res,adj;
    vector<int> vis;
    void dfs(int node,int src)
    {
        if(vis[node]==0 and node!=src)
            res[node].push_back(src);
        vis[node]=1;
        for(auto &child:adj[node])
        {
           if(!vis[child])
            dfs(child,src);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        res.resize(n);
        adj.resize(n);
        for(auto &edge:edges)
            adj[edge[0]].push_back(edge[1]);
        vis.resize(n,0);
        for(int i=0;i<n;i++)
        {
            dfs(i,i);
            fill(vis.begin(),vis.end(),0);
        }
        return res;
    }
};