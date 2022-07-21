class Solution {
public:
    const int mod=1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        int num,sum;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=target;j++)
                dp[i-1][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
            for(int j=1;j<=target;j++)
            {
                if(i==1)
                {
                    if(j<=k)
                        dp[i][j]=1;
                }
                else
                {
                    if(j<=k)
                        dp[i][j]=dp[i-1][j-1];
                    else
                        dp[i][j]=(dp[i-1][j-1]-dp[i-1][j-k-1]+mod)%mod;
                }
            }
        }
        return dp[n][target];
    }
};