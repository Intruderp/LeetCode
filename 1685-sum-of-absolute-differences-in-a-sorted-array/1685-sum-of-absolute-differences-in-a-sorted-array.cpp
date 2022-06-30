class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size(),sum=accumulate(nums.begin(),nums.end(),0),lSum=0;
        vector<int> res(n);
        for(int i=0;i<n;i++)
        {
            res[i]=nums[i]*(2*i-n)+sum-2*lSum;
            lSum+=nums[i];
        }
        return res;
    }
};