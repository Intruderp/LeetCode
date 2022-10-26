class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        long long sum=0,prevSum=0;
        unordered_map<long long,int> cnt;
        for(auto &num:nums)
        {
            sum=(sum+num)%k;
            if(cnt.count(sum%k))
                return true;
            cnt[prevSum]++;
            prevSum=sum;
        }
        return false;
    }
};