class Solution {
public:
    const int mod=1e9+7;
    int dp[100000][3];
    int help(int i,int x,string &s)
    {
        if(i==s.length())
            return x==2;
        if(x>2)
            return 0;
        if(dp[i][x]!=-1)
            return dp[i][x];
        if(x==2)
            return dp[i][x]=help(i+1,s[i]=='S',s)+help(i+1,x+(s[i]=='S'),s)%mod;
        else
            return dp[i][x]=help(i+1,x+(s[i]=='S'),s)%mod;
    }
    int numberOfWays(string s) 
    {
        memset(dp,-1,sizeof(dp));
        return help(0,0,s);
    }
};