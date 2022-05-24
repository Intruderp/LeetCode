class Solution {
public:
    int dp[600][101][101];
    int help(vector<string> &v,int i,int m,int n)
    {
        if(i==v.size())
            return 0;
        int x=0,y=0;
        for(char &c:v[i])
        {
            x+=c=='0';
            y+=c=='1';
        }
        if(dp[i][m][n]!=-1)
            return dp[i][m][n];
        if(x<=m and y<=n)
            return dp[i][m][n]=max(help(v,i+1,m-x,n-y)+1,help(v,i+1,m,n));
        else
            return dp[i][m][n]=help(v,i+1,m,n);
    }
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        memset(dp,-1,sizeof(dp));
        return help(strs,0,m,n);
    }
};