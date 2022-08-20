class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int maxi=0,n=arrival.size(),server;
        set<int> available;
        unordered_map<int,int> cnt;
        for(int i=0;i<k;i++)
            available.insert(i);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++)
        {
            while(!pq.empty() and pq.top().first<=arrival[i])
            {
                available.insert(pq.top().second);
                pq.pop();
            }
            if(available.size()==0)
                continue;
            server=i%k;
            auto it=available.lower_bound(server);
            if(it==available.end())
                it=available.begin();
            server=*it;
            pq.push({arrival[i]+load[i],server});
            available.erase(server);
            maxi=max(maxi,++cnt[server]);
        }
        vector<int> res;
        for(auto &it:cnt)
        {
            if(it.second==maxi)
                res.push_back(it.first);
        }
        return res;
    }
};