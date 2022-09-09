class Solution {
public:
    int dp[100000][2];
    int help(int i,int prev1,int prev2,int swap,vector<int> &nums1,vector<int> &nums2)
    {
        if(i==nums1.size())
            return 0;
        if(dp[i][swap]!=-1)
            return dp[i][swap];
        int res=1e6;
        if(nums1[i]>prev1 and nums2[i]>prev2)
            res=help(i+1,nums1[i],nums2[i],0,nums1,nums2);
        if(nums1[i]>prev2 and nums2[i]>prev1)
            res=min(res,help(i+1,nums2[i],nums1[i],1,nums1,nums2)+1);
        return dp[i][swap]=res;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2)
    {
        memset(dp,-1,sizeof(dp));
        return help(0,-1,-1,0,nums1,nums2);
    }
};