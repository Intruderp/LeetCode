class Solution {
public:
    int dp[600][101][101];
    int help(vector<vector<int>> &v,int i,int m,int n)
    {
        if(i==v.size())
            return 0;
        if(dp[i][m][n]!=-1)
            return dp[i][m][n];
        if(v[i][0]<=m and v[i][1]<=n)
            return dp[i][m][n]=max(help(v,i+1,m-v[i][0],n-v[i][1])+1,help(v,i+1,m,n));
        else
            return dp[i][m][n]=help(v,i+1,m,n);
    }
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        int x=0,y=0;
        vector<vector<int>> v;
        for(string &s:strs)
        {
            x=0,y=0;
            for(char &c:s)
            {
                x+=c=='0';
                y+=c=='1';
            }
            v.push_back({x,y});
        }
        memset(dp,-1,sizeof(dp));
        return help(v,0,m,n);
    }
};