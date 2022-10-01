class Solution {
public:
    bool poss(char c1,char c2)
    {
        int x=(c1-'0')*10+(c2-'0');
        return x<=26;
    }
    int numDecodings(string s)
    {
        int n=s.length();
        if(s[0]=='0')
            return 0;
        if(n==1)
            return 1;
        vector<int> dp(n,0);
        dp[0]=1;
        if(s[1]!='0')
        {
            dp[1]=1+poss(s[0],s[1]);
        }
        else
        {
            dp[1]=poss(s[0],s[1]);
        }
        for(int i=2;i<n;i++)
        {
            if(s[i]=='0')
            {
                if(s[i-1]!='0' and poss(s[i-1],'0'))
                    dp[i]=dp[i-2];
            }
            else
            {
                dp[i]=dp[i-1];
                if(s[i-1]!='0' and poss(s[i-1],s[i]))
                    dp[i]+=dp[i-2];
            }
        }
        return dp[n-1];
    }
    
};