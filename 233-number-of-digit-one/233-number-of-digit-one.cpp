class Solution {
public:
    int dp[10][11][2];
    int help(int i,bool b,string &s,int x)
    {
        if(i==s.length())
            return x;
        if(dp[i][x][b]!=-1)
            return dp[i][x][b];
        int end= b ? 9 :s[i]-'0',res=0;
        for(int j=0;j<=end;j++)
        {
            if(j!=end)
                res+=help(i+1,true,s,x+(j==1));
            else 
                res+=help(i+1,b,s,x+(j==1));
        }
        return dp[i][x][b]=res;
    }
    int countDigitOne(int n) 
    {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return help(0,false,s,0);
    }
};