class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(),i=0,j=0,sum=0,ans=n+1;
        while(i<n)
        {
            while(sum<target and j<n)
            {
                sum+=nums[j];
                j++;
            }
            if(sum>=target)
                ans=min(ans,j-i);
            sum-=nums[i];
            i++;
        }
        return ans==n+1 ? 0:ans;
    }
};