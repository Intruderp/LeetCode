class Solution {
public:
    int dp[10][2][1<<10];
    int help(int i,bool b,int mask,string &s)
    {
        if(i==s.length())
            return 1;
        if(dp[i][b][mask]!=-1)
            return dp[i][b][mask];
        int ans=0;
        for(int digit=0;digit<=9;digit++)
        {
            int newMask=mask;
            if(mask>1 or digit!=0)
                newMask|=(1<<digit);
            if((b or (s[i]-'0')>=digit) and (mask&(1<<digit))==0)
                ans+=help(i+1,b|(s[i]-'0'>digit),newMask,s);
        }
        return dp[i][b][mask]=ans;
    }
    int countSpecialNumbers(int n)
    {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return help(0,0,0,s)-1;
    }
};