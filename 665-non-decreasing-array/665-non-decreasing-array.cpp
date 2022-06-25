class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=0,n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]<nums[i])
            {
                if(i-1>=0 and nums[i-1]>nums[i+1])
                    nums[i+1]=nums[i];
                else
                    nums[i]=nums[i+1];
                cnt++;
            }
        }
        return cnt<=1;
    }
};