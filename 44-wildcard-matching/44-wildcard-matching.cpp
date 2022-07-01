class Solution {
public:
  //  bool help(int i,int j,string &s,string &p)
    bool isMatch(string &s, string &p) 
    {
        int n,m;
        n=s.length();
        m=p.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
        for(int i=0;i<m;i++)
        {
            if(p[i]=='*')
                dp[0][i+1]=1;
            else 
                break;
        }
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] or p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else 
                {
                    if(p[j-1]=='*')
                        dp[i][j]=dp[i-1][j] or dp[i][j-1] or dp[i-1][j-1];
                    else 
                        dp[i][j]=0;
                }
            }
        }
        return dp[n][m];
        
    }
};