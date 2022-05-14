class Solution {
public:
    vector<pair<int,int>> adj[101];
    // void topoSort(int node)
    // {                                        =>For DAG only (Here Acyclic ?)=> Not given
    //     vis[node]=1;
    //     for(auto it:adj[node])
    //     {                                
    //         if(vis[it.first]==0)                             
    //             topoSort(it.first);
    //     }
    //     s.push(node);
    // }
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<int> dist(n+1,INT_MAX);
        dist[0]=0;
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>> q;
        q.push({0,k});
        dist[k]=0;
        while(!q.empty())
        {
            int node=q.top().second;
            int d=-q.top().first;
            q.pop();
            for(auto it:adj[node])
            {
                int ans=d+it.second;
                if(ans<dist[it.first])
                {
                    dist[it.first]=ans;
                    q.push({-ans,it.first});
                }
            }
        }
        int ans=0;
        for(int i:dist)
            ans=max(ans,i);
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};