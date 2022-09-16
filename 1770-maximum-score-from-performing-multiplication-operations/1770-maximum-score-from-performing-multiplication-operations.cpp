class Solution {
public:
    int dp[1002][1002];
    int help(int i,int j,int op,vector<int> & n,vector<int> & m)
    {
        if(i>j || op>=m.size())
            return 0;
        if(dp[i][op]!=INT_MIN)
            return dp[i][op];
        return dp[i][op]=max(m[op]*n[i]+help(i+1,j,op+1,n,m),m[op]*n[j]+help(i,j-1,op+1,n,m));
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
        for(int i=0;i<=1000;i++)
        {
            for(int j=0;j<=1000;j++)
                dp[i][j]=INT_MIN;
        }
        return help(0,nums.size()-1,0,nums,multipliers);
    }
};