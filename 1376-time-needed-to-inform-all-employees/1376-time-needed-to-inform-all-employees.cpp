class Solution {
public:
    int dfs(int src,vector<int> &informTime,vector<int> adj[],vector<int>& manager)
    {
        int ans=0;
        for(auto &child:adj[src])
        {
            ans=max(ans,dfs(child,informTime,adj,manager)+informTime[manager[child]]);
        }
        return ans;
    }
    int numOfMinutes(int n, int headId, vector<int>& manager, vector<int>& informTime) 
    {
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(i==headId)
                continue;
            adj[manager[i]].push_back(i);
        }
        return dfs(headId,informTime,adj,manager);
    }
};