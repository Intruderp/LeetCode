class Solution {
public:
    int dp[1000][1000];
    int help(int i,int prev,int n)
    {
        if(i==n)
            return 0;
        if(i>n)
            return 10000;
        if(dp[i][prev]!=-1)
            return dp[i][prev];
        return dp[i][prev]=min(help(i+prev,prev,n),help(2*i,i,n)+1)+1;
    }
    int minSteps(int n) {
        if(n==1)
            return 0;
        memset(dp,-1,sizeof(dp));
        return help(1,1,n)+1;
    }
};