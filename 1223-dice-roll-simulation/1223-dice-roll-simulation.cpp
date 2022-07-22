class Solution {
public:
    const int mod=1e9+7;
    int dp[5000][7][16];
    int help(int i,int prev,int cnt,int n,vector<int>& rollMax)
    {
        if(prev!=0 and rollMax[prev-1]<cnt)
            return 0;
        if(i==n)
            return 1;
        if(dp[i][prev][cnt]!=-1)
            return dp[i][prev][cnt];
        int ans=0;
        for(int j=1;j<=6;j++)
        {
            ans=(ans+help(i+1,j,j==prev ? cnt+1:1,n,rollMax))%mod;
        }
        return dp[i][prev][cnt]=ans;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp,-1,sizeof(dp));
        return help(0,0,0,n,rollMax);
    }
};