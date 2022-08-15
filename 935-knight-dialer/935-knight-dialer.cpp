class Solution {
public:
    int dx[2]={2,-2},dy[2]={1,-1},mod=1e9+7,dp[4][3][5000];
    int help(int i,int j,int n)
    {
        if(i<0 or j<0 or i>=4 or j>=3)
            return 0;
        if((i==3 and j==0) or (i==3 and j==2))
                return 0;
        if(dp[i][j][n]!=-1)
            return dp[i][j][n];
        if(n==0)
            return 1;
        int ans=0;
        for(auto &x:dx)
        {
            for(auto &y:dy)
            {
                ans=(ans+help(i+x,j+y,n-1))%mod;
                ans=(ans+help(i+y,j+x,n-1))%mod;
            }
        }
        return dp[i][j][n]=ans;
    }
    int knightDialer(int n) 
    {
        int res=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
                res=(res+help(i,j,n-1))%mod;
        }
        return res;
    }
    
};