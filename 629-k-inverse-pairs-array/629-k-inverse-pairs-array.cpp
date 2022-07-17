class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        dp[0][0]=1;
        int mod=1e9+7;
        for (int i = 1; i <= n;i++)
        {
            for (int j = 0; j <= k;j++) 
            {
                dp[i][j] = (dp[i - 1][j] + (j > 0 ? dp[i][j - 1] : 0))%mod;
                if (j >= i)
                    dp[i][j] = (dp[i][j]-dp[i - 1][j-i]+mod)%mod;
            }
        }
        return dp[n][k];
    }
};