class Solution {
public:
    int dp[1000][101][2];
    int help(int i,int k,int available,vector<int> &prices)
    {
        if(k==0 or i==prices.size())
            return 0;
        if(dp[i][k][available]!=-1)
            return dp[i][k][available];
        if(available)
            return dp[i][k][available]=max(help(i+1,k-1,0,prices)+prices[i],help(i+1,k,1,prices));
        else
            return dp[i][k][available]=max(help(i+1,k,1,prices)-prices[i],help(i+1,k,0,prices));
            
    }
    int maxProfit(int k, vector<int>& prices)
    {
        memset(dp,-1,sizeof(dp));
        return help(0,k,0,prices);
    }
};