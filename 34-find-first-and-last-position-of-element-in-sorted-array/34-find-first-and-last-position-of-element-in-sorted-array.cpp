class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int x,y;
        auto it=lower_bound(nums.begin(),nums.end(),target);
        if(it==nums.end() or *it>target)
            x=-1,y=-1;
        else 
        {
            x=it-nums.begin();
            it=upper_bound(nums.begin(),nums.end(),target);
            it--;
            y=it-nums.begin();
        }
        vector<int> ans={x,y};
        return ans;
    }
};