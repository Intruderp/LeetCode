class Solution {
public:
    int dp[10][2][1<<10+1];
    int help(int i,bool b,int cur,string &s)
    {
        if(i==s.length())
            return 1;
        if(dp[i][b][cur]!=-1)
            return dp[i][b][cur];
        int ans=0;
        for(int digit=0;digit<=9;digit++)
        {
            if((b or (s[i]-'0')>=digit) and (cur&(1<<digit))==0)
                ans+=help(i+1,b|(s[i]-'0'>digit),cur|(cur<=1 and digit==0 ? 0:(1<<digit)),s);
        }
        return dp[i][b][cur]=ans;
    }
    int countSpecialNumbers(int n)
    {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return help(0,0,0,s)-1;
    }
};