class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size(),sum=0;
        vector<int> res(n);
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            res[i]=sum;
        }
        return res;
    }
};