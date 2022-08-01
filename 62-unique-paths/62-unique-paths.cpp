class Solution {
public:
    int dp[105][105];
    int help(int i,int j,int m,int n)
    {
        if(i==m && j==n)
            return 1;
        if(i>m || j>n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=help(i+1,j,m,n)+help(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) 
    {
        if(min(n,m)==1)
            return 1;
        long long ans=m;
        for(int i=1;i<=n-2; i++)
        {
            ans=ans*(m+i);
            ans=ans/(i+1);
        }
        return ans;
    }
};