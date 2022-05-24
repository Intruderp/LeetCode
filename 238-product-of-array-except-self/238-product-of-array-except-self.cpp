class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int fromBegin=1,fromEnd=1;
        vector<int> ans(n,1);
        for(int i=0;i<n;i++)
        {
            ans[i]*=fromBegin;
            fromBegin*=nums[i];
            ans[n-i-1]*=fromEnd;
            fromEnd*=nums[n-i-1];
        }
        return ans;
    }
};