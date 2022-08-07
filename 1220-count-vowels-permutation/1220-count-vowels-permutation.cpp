class Solution {
public:
    const int mod=1e9+7;
    int countVowelPermutation(int n) 
    {
        int dp[n+1][6];                     // dp[i][j]= number of strings of lenght i having j as prev character
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=5;i++)
            dp[1][i]=1;
        for(int i=2;i<=n;i++)
        {
            for(int p=1;p<=5;p++)
            {
                if(p==1)
                    dp[i][p]=(dp[i][p]+dp[i-1][2])%mod;
                else if(p==2)
                {
                    dp[i][p]=(dp[i][p]+dp[i-1][1])%mod;
                    dp[i][p]=(dp[i][p]+dp[i-1][3])%mod;
                }
                else if(p==3)
                {
                    for(int j=1;j<=5;j++)
                    {
                        if(j!=3)
                            dp[i][p]=(dp[i][p]+dp[i-1][j])%mod;
                    }
                }
                else if(p==4)
                {
                    dp[i][p]=(dp[i][p]+dp[i-1][5])%mod;
                    dp[i][p]=(dp[i][p]+dp[i-1][3])%mod;
                }
                else
                    dp[i][p]=(dp[i][p]+dp[i-1][1])%mod;
            }
        }
        int ans=0;
        for(int i=1;i<=5;i++)
        {
            ans=(ans+dp[n][i])%mod;
        }
        return ans;
    }
};