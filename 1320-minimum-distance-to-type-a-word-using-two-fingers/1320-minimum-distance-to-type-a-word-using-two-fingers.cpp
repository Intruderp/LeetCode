class Solution {
public:
    int dp[300][26][26];
    int dist(int x,int y)
    {
        int r1=(x+6)/6,r2=(y+6)/6,c1=x%6,c2=y%6;
        return abs(r1-r2)+abs(c1-c2);
    }
    int help(int i,int f1,int f2,string &s)
    {
        if(i==s.length())
            return 0;
        if(dp[i][f1][f2]!=-1)
            return dp[i][f1][f2];
        return dp[i][f1][f2]=min(help(i+1,s[i]-'A',f2,s)+dist(s[i]-'A',f1),help(i+1,f1,s[i]-'A',s)+dist(s[i]-'A',f2));
    }
    int minimumDistance(string word) 
    {
        int res=INT_MAX;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<26;i++)
        {
            res=min(res,help(0,word[0]-'A',i,word));
        }
        return res;
    }
};