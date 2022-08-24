class Solution {
public:
    int dp[65536];
    bool help(int bit,int cur,int k,int &req,int &n,vector<int> &nums)
    {
        if(bit==(2<<(n-1))-1)
        {
            if(cur==req)
                return k==1;
            return false;
        }
        if(k<0)
            return false;
        if(dp[bit]!=-1)
            return dp[bit];
        bool ans=false;
        if(req==cur)
            ans=help(bit,0,k-1,req,n,nums);
        else
        {
            for(int i=0;i<n;i++)
            {
                if(((1<<i)&bit)==0 and cur+nums[i]<=req)
                    ans|=help(bit|(1<<i),cur+nums[i],k,req,n,nums);
            }
        }
        return dp[bit]=ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k)
            return false;
        int n=nums.size(),req=sum/k;
        memset(dp,-1,sizeof(dp));
        return help(0,0,k,req,n,nums);
    }
};