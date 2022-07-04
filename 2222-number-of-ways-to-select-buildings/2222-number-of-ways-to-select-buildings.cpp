class Solution {
public:
    long long dp[100000][4][3];
    long long help(int i,string &s,int cnt,int p)
    {
        if(cnt>3)
            return 0;
        if(i==s.length())
            return cnt==3;
        if(dp[i][cnt][p]!=-1)
            return dp[i][cnt][p];
        if((s[i]-'0')!=p)
            return dp[i][cnt][p]=help(i+1,s,cnt+1,s[i]-'0')+help(i+1,s,cnt,p);
        else
            return dp[i][cnt][p]=help(i+1,s,cnt,p);
    }
    long long numberOfWays(string s) {
        memset(dp,-1,sizeof(dp));
        return  help(0,s,0,2);
    }
};