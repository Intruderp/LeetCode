class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        int n=nums.size(),i=0,j=0,res=0;
        map<int,int> map;
        while(j<n)
        {
            map[nums[j++]]++;
            while(map.rbegin()->first-map.begin()->first>limit)
            {
                map[nums[i]]--;
                if(map[nums[i]]==0)
                    map.erase(nums[i]);
                i++;
            }
            res=max(res,j-i);
        }
        return res;
    }
};