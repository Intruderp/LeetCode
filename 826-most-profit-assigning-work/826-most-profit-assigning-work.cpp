class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> v;
        int n=difficulty.size(),mx=0,res=0;
        for(int i=0;i<n;i++)
            v.push_back({difficulty[i],profit[i]});
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            mx=max(mx,v[i].second);
            v[i].second=mx;
        }
        for(auto &w:worker)
        {
            pair p={w,INT_MAX};
            auto it=upper_bound(v.begin(),v.end(),p);
            if(it!=v.begin())
            {
                it--;
                res+=it->second;
            }
            
        }
        return res;
    }
};