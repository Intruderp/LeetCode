class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum=accumulate(nums.begin(),nums.end(),0ll),lSum=0;
        int n=nums.size(),count=0;
        for(int i=0;i<n-1;i++)
        {
            lSum+=nums[i];
            if(lSum>=(sum-lSum))
                count++;
        }
        return count;
    }
};