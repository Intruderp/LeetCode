class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int node,int par,int vis[],vector<int> adj[],int low[],int in[],int &timer)
    {
        vis[node]=1;
        in[node]=low[node]=timer++;
        for(auto &child:adj[node])
        {
            if(child==par)
                continue;
            if(vis[child])
                low[node]=min(low[node],in[child]);
            else
            {
                dfs(child,node,vis,adj,low,in,timer);
                if(low[child]>in[node])
                    ans.push_back({node,child});
                low[node]=min(low[node],low[child]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        int vis[n],timer=0,low[n],in[n];
        vector<int> adj[n];
        memset(vis,0,sizeof(vis));
        for(auto &connection:connections)
        {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        dfs(0,-1,vis,adj,low,in,timer);
        return ans;
    }
};