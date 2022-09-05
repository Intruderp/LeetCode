class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        vector<int> cnt(n,0);
        priority_queue<int,vector<int>,greater<int>> available;
        priority_queue<pair<long,int>,vector<pair<long,int>>,greater<pair<long,int>>> pq;
        for(int i=0;i<n;i++)
        {
            available.push(i);
        }
        long cur=v[0][0];
        int i=0,room,sz=v.size(),maxi=0,res=-1;
        while(i<sz)
        {
            while(!pq.empty() and pq.top().first<=cur)
            {
                available.push(pq.top().second);
                pq.pop();
            }
            while(i<sz and cur>=v[i][0] and available.size()>0)
            {
                room=available.top();
                cnt[room]++;
                if(cnt[room]>maxi)
                {
                    maxi=cnt[room];
                    res=room;
                }
                else if(cnt[room]==maxi)
                {
                    res=min(res,room);
                }
                available.pop();
                pq.push({cur+(v[i][1]-v[i][0]),room});
                i++;
            }
            cur++;
            if(i<sz)
                cur=max(cur,(long)v[i][0]);
            if(pq.size()>0 and available.size()==0)
                cur=max(cur,pq.top().first);
        }
        return res;
    }
};