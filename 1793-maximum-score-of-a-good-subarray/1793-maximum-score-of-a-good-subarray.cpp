class Solution {
public:
    int maximumScore(vector<int>& nums, int k) 
    {
        int res=nums[k],mn=nums[k],i=k,j=k,n=nums.size();
        while(i>0 and j<n-1)
        {
            if(nums[i-1]>nums[j+1])
                i--;
            else
                j++;
            mn=min({mn,nums[i],nums[j]});
            res=max(res,mn*(j-i+1));
        }
        while(i>0)
        {
            i--;
            mn=min(mn,nums[i]);
            res=max(res,mn*(j-i+1));
        }
        while(j<n-1)
        {
            j++;
            mn=min(mn,nums[j]);
            res=max(res,mn*(j-i+1));
        }
        return res;
    }
};