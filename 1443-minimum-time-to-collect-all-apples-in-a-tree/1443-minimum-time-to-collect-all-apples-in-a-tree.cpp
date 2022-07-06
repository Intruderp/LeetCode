class Solution {
public:
    vector<vector<int>> adj;
    vector<int> subtree,dist;
    int dfs(int src,int par,vector<bool> &hasApple,int d)
    {
        int cur=hasApple[src];
        for(auto &child:adj[src])
        {
            if(child!=par)
                cur+=dfs(child,src,hasApple,d+1);
        }
        dist[src]=d;
        return subtree[src]=cur;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.resize(n);
        dist.resize(n);
        subtree.resize(n,0);
        for(auto &edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0,-1,hasApple,0);
        int res=0;
        for(int i=1;i<n;i++)
        {
            if(hasApple[i])
                res+=dist[i]*2;
            res-=max(0,(subtree[i]-1)*2);
        }
        return res;
    }
};