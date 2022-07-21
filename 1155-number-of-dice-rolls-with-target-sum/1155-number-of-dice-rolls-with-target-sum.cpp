class Solution {
public:
    const int mod=1e9+7;
    int dp[30][1001];
    int help(int i,int n,int k,int target)
    {
        if(target<0)
            return 0;
        if(i==n)
            return target==0;
        if(dp[i][target]!=-1)
            return dp[i][target];
        int ans=0;
        for(int num=1;num<=k;num++)
            ans=(ans+help(i+1,n,k,target-num))%mod;
        return dp[i][target]=ans;
            
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return help(0,n,k,target);
    }
};