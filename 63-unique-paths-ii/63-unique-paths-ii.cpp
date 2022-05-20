class Solution {
public:
    int n,m,dp[105][105];
    int help(vector<vector<int> > & ob,int i,int j)
    {
        if(i>n-1 || j>m-1)
            return 0;
        if(ob[i][j]==1)
            return 0;
        if(i==n-1 && j==m-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=help(ob,i+1,j)+help(ob,i,j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& ob) 
    {
        n=ob.size();
        m=ob[0].size();
        memset(dp,-1,sizeof(dp));
        return help(ob,0,0);
    }
};