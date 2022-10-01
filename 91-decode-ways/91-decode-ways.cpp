class Solution {
public:
    int dp[100];
    bool poss(char c1,char c2)
    {
        int x=(c1-'0')*10+(c2-'0');
        return x<=26;
    }
    int help(int i,string &s)
    {
        if(i==s.length())
            return 1;
        if(s[i]=='0')
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=0;
        ans+=help(i+1,s);
        if(i+1<s.length() and poss(s[i],s[i+1]))
            ans+=help(i+2,s);
        return dp[i]=ans;
    }
    int numDecodings(string s)
    {
        memset(dp,-1,sizeof(dp));
        return help(0,s);
    }
};