class Solution {
public:
    const int mod=1e9+7;
    int dp[50][50][51];
    long long help(int i,int j,int m,int n,int maxMove)
    {
        if(i<0 or j<0 or i>=m or j>=n)
            return 1;
        if(maxMove==0)
            return 0;
        if(dp[i][j][maxMove]!=-1)
            return dp[i][j][maxMove];
        int count=(help(i+1,j,m,n,maxMove-1)+help(i-1,j,m,n,maxMove-1))%mod;
        count=(count+help(i,j+1,m,n,maxMove-1))%mod;
        count=(count+help(i,j-1,m,n,maxMove-1))%mod;
        return dp[i][j][maxMove]=count;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return help(startRow,startColumn,m,n,maxMove);
    }
};