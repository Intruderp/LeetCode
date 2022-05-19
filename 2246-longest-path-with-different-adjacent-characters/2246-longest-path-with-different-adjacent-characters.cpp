class Solution {
public:
    vector<int> adj[100000];
    int dist[100000];
    int ans=1;
    void dfs(int node,string &s)
    {
        dist[node]=1;
        for(auto &child:adj[node])
        {
            dfs(child,s);
            if(s[node]!=s[child])
            {
                ans=max(ans,dist[node]+dist[child]);
                dist[node]=max(dist[node],dist[child]+1);
            }
        }
    }
    int longestPath(vector<int>& parent, string s) 
    {
        int n=s.size();
        for(int i=1;i<n;i++)
        {
            adj[parent[i]].push_back(i);
        }
        dfs(0,s);
        return ans;
    }
};