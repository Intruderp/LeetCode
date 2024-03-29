class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)
            res+=i-freq[i-nums[i]]++;
        return res;
    }
};