class Solution {
public:
    int help(int i,int j,int cnt,vector<int> &nums)
    {
        if(i==j or cnt==0)
            return nums[j]-nums[i];
        return min(help(i+1,j,cnt-1,nums),help(i,j-1,cnt-1,nums));
    }
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return help(0,nums.size()-1,3,nums);
    }
};