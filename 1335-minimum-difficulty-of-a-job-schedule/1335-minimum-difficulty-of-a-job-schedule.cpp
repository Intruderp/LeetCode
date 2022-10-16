class Solution {
public:
    int mx=500000,n,dp[300][10];
    int help(int i,int x,int d,vector<int> &difficulty)
    {
        if(i==n and x<d)
            return mx;
        if(x==d and i<n)
            return mx;
        if(i==n and x==d)
            return 0;
        if(dp[i][x]!=-1)
            return dp[i][x];
        int m=0,ans=mx;
        for(int j=i;j<n;j++)
        {
            m=max(m,difficulty[j]);
            ans=min(ans,help(j+1,x+1,d,difficulty)+m);
        }
        return dp[i][x]=ans;
    }
        
    int minDifficulty(vector<int>& jobDifficulty, int d) 
    {
        n=jobDifficulty.size();
        memset(dp,-1,sizeof(dp));
        int ans=help(0,0,d,jobDifficulty);
        return ans<mx ? ans : -1;
    }
};