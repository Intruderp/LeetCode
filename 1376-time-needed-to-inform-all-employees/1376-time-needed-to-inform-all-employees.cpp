class Solution {
public:
    int numOfMinutes(int n, int headId, vector<int>& manager, vector<int>& informTime) 
    {
        vector<int> adj[n];
        vector<int> dist(n,INT_MAX);
        for(int i=0;i<n;i++){
            if(i==headId)
                continue;
            adj[manager[i]].push_back(i);
        }
        int res=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,headId});
        dist[headId]=0;
        while(!q.empty()){
            auto t=q.top();
            q.pop();
            for(auto &child:adj[t.second])
            {
                if(dist[child]>t.first+informTime[manager[child]])
                {
                    dist[child]=t.first+informTime[manager[child]];
                    q.push({dist[child],child});
                }
            }
        }
        for(int i=0;i<n;i++){
            res=max(res,dist[i]);
        }
        return res;
    }
};