class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int ans=0,max_distance=0,current_end=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            max_distance=max(max_distance,nums[i]+i);
            if(i==current_end)
            {
                current_end=max_distance;
                ans++;
            }
        }
        return ans;
    }
};