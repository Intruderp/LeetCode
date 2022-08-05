class Solution {
public:
    int dp[201][1001];
    int help(int i,int sum,vector<int> &c)
    {
        if(sum==0)
            return 1;
        if(i==c.size())
            return 0;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        if(sum>=c[i])
            return dp[i][sum]=help(0,sum-c[i],c)+help(i+1,sum,c);  // i=0 as order matters 
        else 
            return dp[i][sum]=help(i+1,sum,c);
    }
    int combinationSum4(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        memset(dp,-1,sizeof(dp));
        return help(0,amount,coins);
        
    }
};