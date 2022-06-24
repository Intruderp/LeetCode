class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int i=0,j=0,n=nums.size(),prod=1,ans=0,x;
        while(i<n)
        {
            while(j<n and prod*nums[j]<k)
            {
                prod*=nums[j];
                j++;
            }
            ans+=(j-i);
            if(i<j)
            {
                prod/=nums[i];
                i++;
            }
            else
            {
                i++;
                j++;
            }
        }
        return ans;
    }
};