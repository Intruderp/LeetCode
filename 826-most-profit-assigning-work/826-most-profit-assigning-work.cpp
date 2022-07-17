class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size(),mx=0,res=0;
         vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)
            v[i]={difficulty[i],profit[i]};
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            mx=max(mx,v[i].second);
            v[i].second=mx;
        }
        for(auto &w:worker)
        {
            pair p={w+1,0};
            auto it=lower_bound(v.begin(),v.end(),p);
            if(it!=v.begin())
            {
                it--;
                res+=it->second;
            }
            
        }
        return res;
    }
};