class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        int mod=1e9+7,n=packages.size(),m=boxes.size(),prev;
        long long res=1e15,ans=0,cnt;
        vector<long long> pre(n,0);
        sort(packages.begin(),packages.end());
        pre[0]=packages[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=(pre[i-1]+packages[i]);
        }
        for(int i=0;i<m;i++)
        {
            prev=-1;
            ans=0;
            sort(boxes[i].begin(),boxes[i].end());
            for(auto &box:boxes[i])
            {
                auto it=upper_bound(packages.begin(),packages.end(),box);
                if(it==packages.begin())
                    continue;
                it--;
                cnt=(it-packages.begin())-prev;
                ans+=cnt*box;
                ans-=pre[it-packages.begin()];
                if(prev>=0)
                    ans+=pre[prev];
                prev=it-packages.begin();
            }
            if(prev==n-1)
                res=min(res,ans);
        }
        return res==1e15 ? -1:res%mod;
    }
};