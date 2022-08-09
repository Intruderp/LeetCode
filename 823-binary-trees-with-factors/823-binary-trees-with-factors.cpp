class Solution {
public:
    const int mod=1e9+7;
    unordered_map<int,int> m;
    int dp[1000];
    long long help(int cur,int n,vector<int> &nums)
    {
        if(dp[cur]!=-1)
            return dp[cur];
        int res=1;
        for(int i=0;i<n;i++)
        {
            if(nums[cur]%nums[i]==0 and m.count(nums[cur]/nums[i]))
            {
                res=(res+(help(i,n,nums)*help(m[nums[cur]/nums[i]],n,nums))%mod)%mod; 
            }
        }
        return dp[cur]=res;
    }
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        int res=0,n=arr.size();
        for(int i=0;i<n;i++)
            m[arr[i]]=i;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            res=(help(i,n,arr)+res)%mod;
        }
        return res;
    }
};