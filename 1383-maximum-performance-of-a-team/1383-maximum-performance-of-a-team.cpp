class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        long res=0,sum=0,mini;
        int i=n-1,mod=1e9+7;
        vector<vector<int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({efficiency[i],speed[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int,vector<int>,greater<int>> q;
        while(i>=0)
        {
            if(q.size()==k)
            {
                sum-=q.top();
                q.pop();
            }
            q.push(v[i][1]);
            sum+=v[i][1];
            mini=v[i][0];
            res=max(res,sum*mini);
            i--;
        }
        return res%mod;
    }
};