class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        int mod=1e9+7,n=packages.size(),m=boxes.size(),prev;
        long long res=1e15,cur=0,cnt,packageSum=0;
        sort(packages.begin(),packages.end());
        for(int i=0;i<n;i++)
        {
            packageSum+=packages[i];
        }
        for(int i=0;i<m;i++)
        {
            prev=-1;
            cur=0;
            sort(boxes[i].begin(),boxes[i].end());
            for(auto &box:boxes[i])
            {
                auto it=upper_bound(packages.begin(),packages.end(),box);
                if(it==packages.begin())
                    continue;
                it--;
                cnt=(it-packages.begin())-prev;
                cur+=cnt*box;
                prev=it-packages.begin();
            }
            if(prev==n-1)
                res=min(res,cur);
        }
        return res==1e15 ? -1:(res-packageSum)%mod;
    }
};