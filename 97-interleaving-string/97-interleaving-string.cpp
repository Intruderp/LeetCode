class Solution {
public:
    int dp[101][101];
    bool help(int i,int j,int k,string &s,string &y,string &z)
    {
        if(k==z.length() and i==s.length() and j==y.length())
            return true;
        if(k==z.length())
            return false;
        if((i==s.length() and j==y.length()) or (z[k]!=s[i] and z[k]!=y[j]))
            return false;
        if(dp[i][j]!=-1)
            return dp[i][j];
        bool ans=false;
        if(i<s.length())
        {
            if(s[i]==z[k])
                ans=ans || help(i+1,j,k+1,s,y,z);
        }
        if(j<y.length())
        {
            if(y[j]==z[k])
                ans=ans || help(i,j+1,k+1,s,y,z);
        }
        return dp[i][j]=ans;
        
    }
    bool isInterleave(string s1, string s2, string s3) 
    {
        memset(dp,-1,sizeof(dp));
        return help(0,0,0,s1,s2,s3);
    }
};