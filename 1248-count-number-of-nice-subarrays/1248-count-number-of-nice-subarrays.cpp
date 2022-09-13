class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int sum=0,res=0;
        unordered_map<int,int> cnt;
        cnt[0]=1;
        for(auto &num:nums)
        {
            sum+=num%2;
            if(cnt.count(sum-k))
                res+=cnt[sum-k];
            cnt[sum]++;
        }
        return res;
    }
};