class Solution {
public:
    int numberOfArrays(vector<int>& d, int l, int u) 
    {
        long long ans=0,mx=-1e12,mn=1e12,x=0;
        for(int i:d)
        {
            x+=i;
            mx=max(mx,x);
            mn=min(mn,x);
        }
        for(int i=l;i<=u;i++)
        {
            if(i+mx<=u and i+mn>=l)
                ans++;
        }
        return ans;
    }
};