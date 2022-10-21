class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff)
    {
        map<int,int> m;
        int i=0,n=nums.size();
        for(int j=0;j<n;j++)
        {
            while(j-i>indexDiff)
            {
                m[nums[i]]--;
                if(m[nums[i]]==0)
                    m.erase(nums[i]);
                i++;
            }
            auto it=m.lower_bound(nums[j]);
            if(it!=m.end() and it->first-nums[j]<=valueDiff)
                return true;
            if(it!=m.begin())
            {
                it--;
                if(nums[j]-it->first<=valueDiff)
                    return true;
            }
            m[nums[j]]++;
        }
        return false;
    }
};