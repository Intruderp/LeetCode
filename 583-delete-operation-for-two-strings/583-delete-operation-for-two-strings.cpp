class Solution {
public:
    int n,m,dp[500][500];
    int help(int i,int j,string &x,string &y)
    {
        if(i==n)
            return m-j;
        if(j==m)
            return n-i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(x[i]==y[j])
            return dp[i][j]=help(i+1,j+1,x,y);
        else 
            return dp[i][j]=min(help(i+1,j,x,y),help(i,j+1,x,y))+1;
    }
    int minDistance(string word1, string word2) {
        n=word1.length();
        m=word2.length();
        memset(dp,-1,sizeof(dp));
        return help(0,0,word1,word2);
    }
};