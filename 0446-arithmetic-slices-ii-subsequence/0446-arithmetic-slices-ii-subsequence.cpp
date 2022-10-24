class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int n=nums.size(),ans=0,cnt=0;
        vector<unordered_map<long long,int>> dp(n+1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long long diff=(long long)nums[i]-nums[j];
                cnt=0;
                if(dp[j].count(diff))
                    cnt=dp[j][diff];
                dp[i][diff]+=cnt+1;
                ans+=cnt;
            }
        }
        return ans;
    }
};