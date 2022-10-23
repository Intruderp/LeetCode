class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) 
    {
        long long res=1e15,lCost=0,rCost=0,sum=0,prefix=0;
        vector<pair<int,long long>> v;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],cost[i]});
        }
        sort(v.begin(),v.end());
        for(int i=1;i<n;i++)
        {
            rCost+=(v[i].first-v[0].first)*v[i].second;
            sum+=v[i].second;
        }
        res=rCost;
        for(int i=1;i<n;i++)
        {
            rCost-=(v[i].first-v[i-1].first)*sum;
            sum-=v[i].second;
            prefix+=v[i-1].second;
            lCost+=(v[i].first-v[i-1].first)*prefix;
            res=min(res,lCost+rCost);
        }
        return res;
    }
};