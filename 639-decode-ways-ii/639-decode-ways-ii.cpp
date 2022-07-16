class Solution {
public:
    const int mod=1e9+7;
    int dp[100000];
    bool valid(int x,int y)
    {
        return x==2 ? y<7 : x<2;
    }
    int help(int i,string &s)
    {
        if(i==s.length())
            return 1;
        if(s[i]=='0')
            return 0;
        if(i==s.length()-1)
            return s[i]=='*' ? 9:1;
        if(dp[i]!=-1)
            return dp[i];
        int cnt=0;
        if(s[i]=='*')
        {
            for(int c=1;c<=9;c++)
                cnt=(cnt+help(i+1,s))%mod;
            if(s[i+1]=='*')
            {
                for(int c=1;c<=2;c++)
                {
                    for(int c2=1;c2<=9;c2++)
                    {
                        if(valid(c,c2))
                            cnt=(cnt+help(i+2,s))%mod;
                    }
                }
            }
            else
            {
                for(int c=1;c<=2;c++)
                {
                    if(valid(c,s[i+1]-'0'))
                        cnt=(cnt+help(i+2,s))%mod;
                }
            }
        }
        else
        {
            cnt=(cnt+help(i+1,s))%mod;
            if(s[i+1]=='*')
            {
                for(int c=1;c<=9;c++)
                {
                    if(valid(s[i]-'0',c))
                        cnt=(cnt+help(i+2,s))%mod;
                }
            }
            else if(valid(s[i]-'0',s[i+1]-'0'))
                cnt=(cnt+help(i+2,s))%mod;
        }
        return dp[i]=cnt;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return help(0,s);
    }
};