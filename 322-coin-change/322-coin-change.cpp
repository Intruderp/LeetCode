class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n=coins.size();
        // int dp[n+1][amount+1];
        // for(int i=0;i<=n;i++)
        //     for(int j=0;j<=amount;j++)
        //         dp[i][j]=0;
        // for(int i=0;i<=amount;i++)
        //     dp[0][i]=INT_MAX-1;
        // for(int i=0;i<=n;i++)
        //     dp[i][0]=0;
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=amount;j++)
        //     {
        //         if(coins[i-1]<=j)
        //             dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
        //         else
        //             dp[i][j]=dp[i-1][j];
        //         //cout<<dp[i][j]<<' ';
        //     }
        //     //cout<<endl;
        // }
        // if(dp[n][amount]==INT_MAX-1)
        //     return -1;
        // return dp[n][amount];
        int dp[amount+1];
        dp[0]=0;
        for(int i=1;i<=amount;i++)
            dp[i]=1e8;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(coins[j]<=i)
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
           // cout<<i<<' '<<dp[i]<<endl;
        }
        if(dp[amount]>amount)
            dp[amount]=-1;
        return dp[amount];
        
    }
};