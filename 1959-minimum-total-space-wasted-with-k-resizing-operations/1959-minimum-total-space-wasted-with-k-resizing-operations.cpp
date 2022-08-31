class Solution {
public:
    int dp[200][201];
    int help(int i,int k,int &n,vector<int> &nums)
    {
        if(k<0)
            return 2e8;
        if(i==nums.size())
            return 0;
        if(dp[i][k]!=-1)
            return dp[i][k];
        int ans=INT_MAX,maxi=0,wasted=0,sum=0;
        for(int j=i;j<n;j++)
        {
            maxi=max(maxi,nums[j]);
            sum+=nums[j];
            wasted=maxi*(j-i+1)-sum;
            ans=min(ans,help(j+1,k-1,n,nums)+wasted);
        }
        return dp[i][k]=ans;
        
    }
    int minSpaceWastedKResizing(vector<int>& nums, int k) 
    {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return help(0,k+1,n,nums);
    }
};