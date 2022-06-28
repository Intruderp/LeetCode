class Solution {
public:
    int numOfMinutes(int n, int headId, vector<int>& manager, vector<int>& informTime) 
    {
        vector<pair<int,int>> adj[n];
        vector<int> dist(n,INT_MAX);
        for(int i=0;i<n;i++){
            if(i==headId)
                continue;
            adj[manager[i]].push_back({i,informTime[manager[i]]});
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
                if(dist[child.first]>t.first+child.second)
                {
                    dist[child.first]=t.first+child.second;
                    q.push({dist[child.first],child.first});
                }
            }
        }
        for(int i=0;i<n;i++){
            res=max(res,dist[i]);
        }
        return res;
    }
};