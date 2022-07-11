class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int res=0,n=nums.size(),i=0,j=0,cur=0;
        sort(nums.rbegin(),nums.rend());
        while(j<n)
        {
            while(j+1<n and cur+nums[i]-nums[j+1]<=k)
            {
                cur+=nums[i]-nums[j+1];
                j++;
            }
            res=max(res,j-i+1);
            if(i+1<n)
            {
                cur-=(nums[i]-nums[i+1])*(j-i);
            }
            i++;
            if(j<i)
                j=i;
        }
        return res;
    }
};