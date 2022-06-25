class Solution {
public:
    bool check(vector<int> &nums)
    {
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]<nums[i])
                return false;
        }
        return true;
    }
    bool checkPossibility(vector<int>& nums) {
        int cnt=0,n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]<nums[i])
            {
                int temp=nums[i];
                nums[i]=nums[i+1];
                bool ans=check(nums);
                nums[i]=temp;
                nums[i+1]=nums[i];
                ans|=check(nums);
                return ans;
            }
        }
        return true;
    }
};