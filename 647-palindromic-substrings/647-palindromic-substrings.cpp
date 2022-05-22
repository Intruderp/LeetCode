class Solution {
public:
    int countSubstrings(string s) 
    {
        int n=s.length(),ans=n;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<=1;i++)
        {
            for(int j=0;j<=n;j++)
                dp[j][i]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=2;j<=i;j++)
            {
                if(s[i-1]==s[i-j] and dp[i-1][j-2])
                {
                    ans++;
                    dp[i][j]=1;
                }
            }
        }
        return ans;
    }
};