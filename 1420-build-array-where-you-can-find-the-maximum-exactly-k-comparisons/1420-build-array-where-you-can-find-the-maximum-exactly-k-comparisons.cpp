class Solution {
public:
    const int mod=1e9+7;
    int dp[50][51][101];
    int help(int i,int m,int k,int mx,int n)
    {
        if(k<0)
            return 0;
        if(i==n)
            return k==0;
        if(dp[i][k][mx]!=-1)
            return dp[i][k][mx];
        int ans=0;
        for(int j=1;j<=m;j++)
        {
            if(j>mx)
                ans=(ans+help(i+1,m,k-1,j,n))%mod;
            else
                ans=(ans+help(i+1,m,k,mx,n))%mod;
        }
        return dp[i][k][mx]=ans;
        
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return help(0,m,k,0,n);
    }
};