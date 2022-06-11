class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size(),i=0,j=0,ans=n+1,sum=accumulate(nums.begin(),nums.end(),0);
        while(i<n)
        {
            while(sum>x and j<n)
            {
                sum-=nums[j];
                j++;
            }
            if(sum==x)
                ans=min(ans,i+n-j);
            x-=nums[i];
            i++;
        }
        return ans==n+1 ? -1:ans;
    }
};