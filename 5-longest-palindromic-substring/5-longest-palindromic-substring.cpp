class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n=s.length();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)
            dp[0][i]=dp[1][i]=1;
        
        for(int i=2;i<=n;i++)                   //traversing for length
        {
            for(int j=i;j<=n;j++)                // ending position for substring
            {
                if(s[j-1]==s[j-i] and dp[i-2][j-1])
                    dp[i][j]=1;
                else 
                    dp[i][j]=0;
            }
        }
        string ans;
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=n;j++)
            {
                if(dp[i][j])
                    return s.substr(j-i,i);
            }
        }
        return ans;
    }
};