class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size(),i=0,j=0;
        int ans=0,sum=0;
        vector<int> cnt(10001,0);
        while(i<n)
        {
            while(j<n and cnt[nums[j]]==0)
            {
                cnt[nums[j]]++;
                sum+=nums[j];
                j++;
            }
            ans=max(ans,sum);
            sum-=nums[i];
            cnt[nums[i]]--;
            i++;
        }
        return ans;
    }
};