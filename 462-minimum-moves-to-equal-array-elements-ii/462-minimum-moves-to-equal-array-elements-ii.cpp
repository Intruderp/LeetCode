class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0,sum2=0,n=nums.size(),x=nums[n/2],y=nums[n/2];
        if(n%2==0)
            y=nums[n/2-1];
        for(int &num:nums)
        {
            sum+=abs(num-x);
            sum2+=abs(num-y);
        }
        return min(sum,sum2);
            
    }
};