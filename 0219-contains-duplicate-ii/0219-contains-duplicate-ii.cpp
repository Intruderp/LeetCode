class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        int n=nums.size();
        unordered_map<int,int> ind;
        for(int i=0;i<n;i++)
        {
            if(ind.count(nums[i]))
            {
                if(i-ind[nums[i]]<=k)
                    return true;
            }
            ind[nums[i]]=i;
        }
        return false;
    }
};