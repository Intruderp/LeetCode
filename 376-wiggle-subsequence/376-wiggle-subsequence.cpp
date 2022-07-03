class Solution {
public:
    int dp[1000][1000][4];
    int help(int i,vector<int> &nums,int p,int x)
    {
        if(i==nums.size())
            return 0;
        int d;
        if(dp[i][p][x]!=-1)
            return dp[i][p][x];
        if(p==0)
            return dp[i][p][x]=max(help(i+1,nums,i+1,1)+1,help(i+1,nums,p,1));
        else if(x==1)
        {
            d=nums[i]-nums[p-1];
            if(d==0)
                return dp[i][p][x]=help(i+1,nums,p,x);
            else if(d>0)
                return dp[i][p][x]=max(help(i+1,nums,i+1,2)+1,help(i+1,nums,p,x));
            else 
                return dp[i][p][x]=max(help(i+1,nums,i+1,3)+1,help(i+1,nums,p,x));
        }
        else if(x==2)
        {
            d=nums[i]-nums[p-1];
            if(d>=0)
                return dp[i][p][x]=help(i+1,nums,p,x);
            else 
                return dp[i][p][x]=max(help(i+1,nums,i+1,3)+1,help(i+1,nums,p,x));
        }
        else
        {
            d=nums[i]-nums[p-1];
            if(d<=0)
                return dp[i][p][x]=help(i+1,nums,p,x);
            else 
                return dp[i][p][x]=max(help(i+1,nums,i+1,2)+1,help(i+1,nums,p,x));
        }
        return 0;
            
        
    }
    int wiggleMaxLength(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        return help(0,nums,0,0);
    }
};