class Solution {
public:
    int minimumCardPickup(vector<int>& nums) {
        int res=INT_MAX,i=0,j=0,n=nums.size();
        unordered_map<int,int> freq;
        while(j<n)
        {
            while(j<n and freq[nums[j]]==0)
            {
                freq[nums[j]]=1;
                j++;
            }
            if(j<n and nums[i]==nums[j])
                res=min(res,j-i+1);
            freq[nums[i]]--;
            i++;
        }
        return res==INT_MAX ? -1:res;
    }
};