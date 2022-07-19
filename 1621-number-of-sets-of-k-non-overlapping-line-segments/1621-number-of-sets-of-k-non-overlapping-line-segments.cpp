class Solution {
public:
    const int mod=1e9+7;
    int dp[1001][1000][2];
    int help(int i,int c,int k,int n)
    {
        if(k<0)
            return 0;
        if(i==n-1)
        {
            if(c)
                return k==1;
            else
                return k==0;
        }
        if(dp[i][k][c]!=-1)
            return dp[i][k][c];
        if(c)
            return dp[i][k][c]=(help(i+1,c,k,n)+help(i,0,k-1,n))%mod;
        else
            return dp[i][k][c]=(help(i+1,c,k,n)+help(i+1,1,k,n))%mod;
    }
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return help(0,0,k,n);
    }
};