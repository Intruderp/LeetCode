class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res=0,n=nums.size();
        vector<int> bit(32,0);
        for(int i=0;i<n;i++)
        {
            for(int b=0;b<32;b++)
            {
                if(((1<<b)&nums[i]))
                {
                    res+=i-bit[b];
                    bit[b]++;
                }
                else
                    res+=bit[b];
            }
        }
        return res;
    }
};