class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long sum=0;
        for(auto &bean:beans)
            sum+=bean;
        sort(beans.begin(),beans.end());
        long long res=1e10;
        int n=beans.size();
        for(int i=0;i<n;i++)
        {
            res=min(res,sum-(long long)beans[i]*(n-i));
        }
        return res;
    }
};